
// Copyright (c) 2018 brinkqiang (brink.qiang@gmail.com)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMMSG_PARSER_H_INCLUDE__
#define __DMMSG_PARSER_H_INCLUDE__

#include "dmos.h"
#include "dmpacketparser.h"

#include <google/protobuf/message.h>

enum PROTO_STYLE : int32_t
{
	PROTO_STYLE_NC = 0,
	PROTO_STYLE_NOTHING = 1,

    PROTO_STYLE_PROTOBUF_BEGIN = 100,
	PROTO_STYLE_LIGHT = 100,
	PROTO_STYLE_DMSTYLE = 101,
	PROTO_STYLE_RPC = 102,

    PROTO_STYLE_PROTOBUF_END = 150,
};

class IDMMsgParserSession
{
public:
    virtual ~IDMMsgParserSession() {}

    virtual void DMAPI OnMessageInline(uint16_t msgID, const std::string& data,
                                       int size) = 0;

    virtual void DMAPI OnMessage(uint16_t msgID, void* data, int size) = 0;

    virtual bool DMAPI Send(const char* data, int size) = 0;

    virtual int DMAPI OnRecv(const char* data, int size) = 0;
};

class IDMMsgParserModule
{
public:
    virtual ~IDMMsgParserModule() {}

    virtual void DMAPI Release(void) = 0;

    virtual void DMAPI Test(void) = 0;

    virtual int DMAPI OnRecv(const char* data, int size) = 0;

    virtual void DMAPI DoClose(const std::string& strError) = 0;

    virtual bool DMAPI SendMsg(uint16_t msgID,
                               ::google::protobuf::Message& msg) = 0;

	virtual bool DMAPI Send(uint16_t msgID, const char* data, int size) = 0;

    virtual void DMAPI SetPacketParser(IDMPacketParser* sink) = 0;

    virtual void DMAPI SetMsgSession(IDMMsgParserSession* sink) = 0;
};

struct DMMsgParserModuleDeleter
{
    inline void operator()(IDMMsgParserModule* module) const
    {
        if (module)
        {
            module->Release();
        }
    }
};


IDMMsgParserModule* DMAPI DMMsgParserGetModule(PROTO_STYLE eMsg = PROTO_STYLE_NC);

typedef IDMMsgParserModule* (DMAPI* PFN_DMMsgParserGetModule)();


class CDMMsgParserSession : public IDMMsgParserSession
{
public:
    CDMMsgParserSession()
        : m_eProtoStyle(PROTO_STYLE_DMSTYLE)
    {

    }

    virtual ~CDMMsgParserSession()
    {

    }


    virtual void DMAPI OnMessageInline(uint16_t msgID, const std::string& data,
                                       int size)
    {
        OnMessage(msgID, (void*)(data.data() + size), data.size() - size);
    }

    virtual int DMAPI OnRecv(const char* data, int size)
    {
        return m_module.get()->OnRecv(data, size);
    }

    virtual bool DMAPI SendMsg(uint16_t wMsgID, ::google::protobuf::Message& msg)
    {
        DMASSERT(HasProtobuf());
        return m_module.get()->SendMsg(wMsgID, msg);
    }

public:
	bool DMAPI SessionInit(PROTO_STYLE eProtoStyle = PROTO_STYLE_DMSTYLE)
	{
		auto module = DMMsgParserGetModule(eProtoStyle);
		if (nullptr == module)
		{
			return false;
		}

		m_eProtoStyle = eProtoStyle;

		m_module.reset(module);
		m_module->SetMsgSession(this);
		return true;
	}

    PROTO_STYLE GetProtoStyle()
    {
        return m_eProtoStyle;
    }

    bool HasProtobuf()
    {
        if (m_eProtoStyle >= PROTO_STYLE_PROTOBUF_BEGIN
            && m_eProtoStyle <= PROTO_STYLE_PROTOBUF_END)
        {
            return true;
        }
        return false;
    }

private:
    std::unique_ptr<IDMMsgParserModule, DMMsgParserModuleDeleter> m_module;
    PROTO_STYLE m_eProtoStyle;
};

#endif // __DMMSG_PARSER_H_INCLUDE__