
#ifndef __DMPACKETPARSER_H_INCLUDE__
#define __DMPACKETPARSER_H_INCLUDE__

#include "dmtypes.h"
#include "dmos.h"
#include "dmsingleton.h"
#include "dmmsgheader.h"

class IDMPacketParser
{
public:
    virtual ~IDMPacketParser() {}
    virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen) = 0;
    virtual int32_t DMAPI GetPacketHeaderSize() = 0;
    virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
                                            uint16_t wMsgID) = 0;
    virtual int32_t DMAPI CheckPacketHeader(void* pHeader) = 0;
    virtual uint16_t DMAPI GetMsgID(void* pHeader) = 0;
    virtual uint16_t DMAPI GetServiceID(void* pHeader) { return 0; }
};

static inline const char* dm_memnctr(const char* src, size_t len, char flag)
{
    for (size_t i=0; i < len; ++i)
    {
        if (src[i] == flag)
        {
            return &src[i];
        }
    }

    return NULL;
}

class HPacketParser :
    public IDMPacketParser,
    public TSingleton<HPacketParser>
{
    friend class TSingleton<HPacketParser>;
public:
    virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen);
    virtual int32_t DMAPI GetPacketHeaderSize();

    virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
                                            uint16_t wMsgID);
    virtual int32_t DMAPI CheckPacketHeader(void* pHeader);
    virtual uint16_t DMAPI GetMsgID(void* pHeader);
private:
    HPacketParser() {}
    virtual ~HPacketParser() {}
};

class HDMPacketParser :
    public IDMPacketParser,
    public TSingleton<HDMPacketParser>
{
    friend class TSingleton<HDMPacketParser>;
public:
    virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen);
    virtual int32_t DMAPI GetPacketHeaderSize();

    virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
                                            uint16_t wMsgID);
    virtual int32_t DMAPI CheckPacketHeader(void* pHeader);
    virtual uint16_t DMAPI GetMsgID(void* pHeader);
private:
    HDMPacketParser() {}
    virtual ~HDMPacketParser() {}
};

class HNothingParser :
    public IDMPacketParser,
    public TSingleton<HNothingParser>
{
    friend class TSingleton<HNothingParser>;
public:
    virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen)
    {
        return nLen;
    }

    virtual int32_t DMAPI GetPacketHeaderSize()
    {
        return 0;
    }

    virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
                                            uint16_t wMsgID)
    {
        return 0;
    }
    virtual int32_t DMAPI CheckPacketHeader(void* pHeader)
    {
        return 0;
    }
    virtual uint16_t DMAPI GetMsgID(void* pHeader)
    {
        return 0;
    };
private:
    HNothingParser() {}
    virtual ~HNothingParser() {}
};

class HNCParser :
    public IDMPacketParser,
    public TSingleton<HNCParser>
{
    friend class TSingleton<HNCParser>;
public:
    virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen)
    {
        const char* p = dm_memnctr(pBuf, nLen, '\n');

        if (NULL == p)
        {
            return 0;
        }

        return (int32_t)(p - pBuf + 1);
    }
    virtual int32_t DMAPI GetPacketHeaderSize()
    {
        return 0;
    }
    virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
                                            uint16_t wMsgID)
    {
        return 0;
    }
    virtual int32_t DMAPI CheckPacketHeader(void* pHeader)
    {
        return 0;
    }
    virtual uint16_t DMAPI GetMsgID(void* pHeader)
    {
        return 0;
    };
private:
    HNCParser() {}
    virtual ~HNCParser() {}
};

class HRpcPacketParser :
	public IDMPacketParser,
	public TSingleton<HRpcPacketParser>
{
	friend class TSingleton<HRpcPacketParser>;
public:
	virtual int32_t DMAPI ParsePacket(const char* pBuf, int32_t nLen);
	virtual int32_t DMAPI GetPacketHeaderSize();
	virtual int32_t DMAPI BuildPacketHeader(void* pHeader, int32_t nDataLen,
		uint16_t wMsgID);
	virtual int32_t DMAPI CheckPacketHeader(void* pHeader);
	virtual uint16_t DMAPI GetMsgID(void* pHeader);
    virtual uint16_t DMAPI GetServiceID(void* pHeader);
private:
    HRpcPacketParser() {}
	virtual ~HRpcPacketParser() {}
};


typedef std::deque<std::string> DMMESSAGE_QUEUE;

const int  DMSEND_BUF_MAX = 65535;
const int  DMRECV_BUF_MAX = 65535;
const int  DM_BUF_MAX = 65535;

#endif // __DMPACKETPARSER_H_INCLUDE__

