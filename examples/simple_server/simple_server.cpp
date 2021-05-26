/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file is part of zmqpp.
 * Copyright (c) 2011-2015 Contributors as noted in the AUTHORS file.
 */

#include <zmqpp/zmqpp.hpp>
#include <string>
#include <iostream>

#include "dmutil.h"
#include "dmtimermodule.h"
#include "dmsingleton.h"
#include "dmthread.h"
#include "dmconsole.h"
#include "dmtypes.h"
#include "dmmsgparsertest/person.pb.h"

#include "dmflags.h"

DEFINE_string(URL, "tcp://*:4242", "url");

#include "dmmsgparser.h"
#include <memory>
#include "person.msg.h"

class CMain;

class CPlayer : public CDMMsgParserSession
    , public CDMDispatcher_db
    , public zmqpp::socket
{
public:
    CPlayer(zmqpp::context_t const& context, zmqpp::socket_type const type)
        : zmqpp::socket(context, type)
    {
        CDMDispatcher_db::Init();
    }

    virtual ~CPlayer()
    {
    }

    virtual void DMAPI OnMessage(uint16_t msgID, void* data, int size)
    {
        NetCall(msgID, data, size, this);
    }

    virtual bool DMAPI Send(const char* data, int size)
    {
        zmqpp::message message;
        message.add_raw(data, size);
        return send(message);
    }

    virtual int Ontb_Person(::google::protobuf::Message& msg, int nLen,
                            const void* pObject);
public:
    template<class T>
    bool DMAPI SendMsg(T& msg)
    {
        return CDMMsgParserSession::SendMsg(GetMsgID<T>(), msg);
    }
};

class CMain :
    public IDMConsoleSink,
    public IDMThread,
    public CDMThreadCtrl,
    public CDMTimerNode,
    public TSingleton<CMain>
{
    friend class TSingleton<CMain>;

    typedef enum
    {
        eTimerID_UUID = 0,
        eTimerID_STOP,
    } ETimerID;

    typedef enum
    {
        eTimerTime_UUID = 1000,
        eTimerTime_STOP = 200000,
    } ETimerTime;

public:

    virtual void ThrdProc()
    {

        const std::string endpoint = FLAGS_URL;

        // bind to the socket
        std::cout << "Binding to " << endpoint << "..." << std::endl;
        m_context.set(zmqpp::context_option::io_threads,
                      std::thread::hardware_concurrency());
        m_oPlayer.bind(endpoint);

        m_looper.add(m_oPlayer, std::bind(&CMain::handle_message, std::ref(m_oPlayer)),
                     zmqpp::poller::poll_in | zmqpp::poller::poll_error);

        std::cout << "test start" << std::endl;

        SetTimer(eTimerID_UUID, eTimerTime_UUID,
                 dm::any(std::string("hello world")));
        SleepMs(300);
        CDMTimerModule::Instance()->Run();

        SetTimer(eTimerID_STOP, eTimerTime_STOP, eTimerTime_STOP * 2);

        bool bBusy = false;

        while (!m_bStop)
        {
            bBusy = false;

            if (CDMTimerModule::Instance()->Run())
            {
                bBusy = true;
            }

            if (__Run())
            {
                bBusy = true;
            }

            if (!bBusy)
            {
                SleepMs(1);
            }
        }

        std::cout << "test stop" << std::endl;
    }

    virtual void Terminate()
    {
        m_bStop = true;
    }

    virtual void OnCloseEvent()
    {
        Stop();
    }

    static bool handle_message(CPlayer& player)
    {
        bool busy = false;

        for (int i=0; i < 10000; i++)
        {
            std::string strData;
            auto res = player.receive(strData, true);

            if (res)
            {
                busy = true;
                player.OnRecv(strData.data(), strData.size());
                continue;
            }

            break;
        }

        return busy;
    }

    virtual void OnTimer(uint64_t qwIDEvent, dm::any& oAny)
    {
        switch (qwIDEvent)
        {
        case eTimerID_UUID:
        {
            std::cout << DMFormatDateTime() << " " << CMain::Instance()->GetOnTimerCount()
                      << " " << dm::any_cast<std::string>(oAny) << std::endl;
        }
        break;

        case eTimerID_STOP:
        {
            std::cout << DMFormatDateTime() << " test stopping..." << std::endl;
            Stop();
        }
        break;

        default:
            break;
        }
    }

    void AddOnTimerCount()
    {
        ++m_qwOnTimerCount;
    }
    uint64_t GetOnTimerCount()
    {
        uint64_t qwSCount = m_qwOnTimerCount - m_qwLastCount;

        m_qwLastCount = m_qwOnTimerCount;
        return qwSCount;
    }
private:
    CMain()
        : m_bStop(false), m_qwOnTimerCount(0), m_qwLastCount(0), m_oPlayer(m_context,
                zmqpp::socket_type::server)
    {
        HDMConsoleMgr::Instance()->SetHandlerHook(this);
    }

    virtual ~CMain()
    {

    }

private:
    bool __Run()
    {
        int event = m_looper.poll(10);

        if (event == 0)
        {
            return false;
        }

        return true;
    }
private:
    volatile bool   m_bStop;

    uint64_t  m_qwOnTimerCount;
    zmqpp::context m_context;

    zmqpp::loop m_looper;

    uint64_t  m_qwLastCount;

    CPlayer m_oPlayer;
};

int CPlayer::Ontb_Person(::google::protobuf::Message& msg, int nLen,
                         const void* pObject)
{
    ::db::tb_Person* pData = dynamic_cast<::db::tb_Person*>(&msg);

    db::tb_Person tb;

    tb.set_uuid(1);
    tb.set_job(2);

    tb.set_name("tom");
    tb.set_number(1366532956);
    tb.set_email("tom@163.com");
    tb.set_phonetype(db::PhoneType::MOBILE);
    tb.set_money(10000);
    tb.set_cash(10000);

    if (pData->SerializeAsString() == tb.SerializeAsString())
    {
        CMain::Instance()->AddOnTimerCount();
    }

    return 0;
}

int main(int argc, char* argv[])
{
    DMFLAGS_INIT(argc, argv);
    CMain::Instance()->Start(CMain::Instance());
    CMain::Instance()->WaitFor();
    return 0;
}
