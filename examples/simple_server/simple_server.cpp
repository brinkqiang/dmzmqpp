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

class CPlayer : public CDMTimerNode
{
public:
    virtual void OnTimer(uint64_t qwIDEvent);
};

class CMain :
    public IDMConsoleSink,
    public IDMThread,
    public CDMThreadCtrl,
    public CDMTimerNode,
    public TSingleton<CMain>
{
    friend class TSingleton<CMain>;

    enum
    {
        eMAX_PLAYER = 100 * 10000,
        eMAX_PLAYER_EVENT = 10,
    };

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

        const std::string endpoint = "tcp://*:4242";

        // bind to the socket
        std::cout << "Binding to " << endpoint << "..." << std::endl;
        m_context.set(zmqpp::context_option::io_threads,
                      std::thread::hardware_concurrency());
        m_socket.bind(endpoint);
        m_looper.add(m_socket, std::bind(&CMain::handle_message, std::ref(m_socket)),
                     zmqpp::poller::poll_in | zmqpp::poller::poll_error);

        std::cout << "test start" << std::endl;

        SetTimer(eTimerID_UUID, eTimerTime_UUID,
                 dm::any(std::string("hello world")));
        SleepMs(300);
        CDMTimerModule::Instance()->Run();

        SetTimer(eTimerID_STOP, eTimerTime_STOP, eTimerTime_STOP * 2);
        // test interface
        uint64_t qwElapse = GetTimerElapse(eTimerID_UUID);
        std::cout << "test GetTimerElapse: " << qwElapse << std::endl;
        uint64_t qwRemain = GetTimerRemain(eTimerID_UUID);
        std::cout << "test GetTimerRemain: " << qwRemain << std::endl;
        CDMTimerElement* poElement = GetTimerElement(eTimerID_UUID);
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

    static bool handle_message(zmqpp::socket& socket)
    {
        bool busy = false;

        for (int i=0; i < 10000; i++)
        {
            zmqpp::message msg;
            auto res = socket.receive(msg, true);

            if (res)
            {
                busy = true;

                db::tb_Person tb;

                tb.set_uuid(1);
                tb.set_job(2);

                tb.set_name("tom");
                tb.set_number(1366532956);
                tb.set_email("tom@163.com");
                tb.set_phonetype(db::PhoneType::MOBILE);
                tb.set_money(10000);
                tb.set_cash(10000);

                if (msg.get(0) == tb.SerializeAsString())
                {
                    CMain::Instance()->AddOnTimerCount();
                }

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
        : m_bStop(false), m_qwOnTimerCount(0), m_socket (m_context,
                zmqpp::socket_type::server), m_qwLastCount(0)
    {
        HDMConsoleMgr::Instance()->SetHandlerHook(this);
    }

    virtual ~CMain()
    {

    }

private:
    bool __Run()
    {
        int event = m_looper.poll(1000);

        if (event == 0)
        {
            return false;
        }

        return true;
    }
private:
    volatile bool   m_bStop;

    CPlayer m_oPlayers[eMAX_PLAYER];

    uint64_t  m_qwOnTimerCount;
    zmqpp::context m_context;
    zmqpp::socket m_socket;

    zmqpp::loop m_looper;

    uint64_t  m_qwLastCount;
};

void CPlayer::OnTimer(uint64_t qwIDEvent)
{

}

int main(int argc, char* argv[])
{
    CMain::Instance()->Start(CMain::Instance());
    CMain::Instance()->WaitFor();
    return 0;
}
