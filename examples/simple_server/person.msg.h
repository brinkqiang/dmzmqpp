/********************************************************************
**       This head file is generated by program,                   **
**            Please do not change it directly.                    **
**                   Auther: brinkqiang                            **
********************************************************************/
// source: person.proto
/********************************************************************
// sample
#include "person.msg.h"
class MyCDMDispatcher_db : public CDMDispatcher_db
{
public:
    virtual ~MyCDMDispatcher_db(){}

    virtual int Ontb_Person(::google::protobuf::Message& msg, int nLen, const void* pObject){ return 0;}
};
********************************************************************/
#ifndef __PERSON_MSG_H__
#define __PERSON_MSG_H__

#include <string>

#include <google/protobuf/message.h>
#include "msgdispatcher.sys.h"
#include "person.pb.h"


// -------------------------------------------------------------------

class CDMDispatcher_db : public TMsgDispatcherPB<CDMDispatcher_db>
{
public:
    CDMDispatcher_db(){}
    virtual ~CDMDispatcher_db(){}

    bool Init();

    int NetCall(uint16_t wMsgID, void* pData, int nLen, const void* pObject);

    ::google::protobuf::Message* CreateMessage(uint16_t wMsgID);
    void ReleaseMessage(::google::protobuf::Message* poMsg);

public:

    virtual int Ontb_Person(::google::protobuf::Message& msg, int nLen, const void* pObject);
};

       
template<>
inline uint16_t GetMsgID<::db::tb_Person>()
{
    return ::db::MSGID::MSGID_tb_Person;
}


#endif  // __PERSON_MSG_H__
