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
#include "dmmsgparsertest/person.pb.h"
#include "dmflags.h"

DEFINE_string(URL, "tcp://localhost:4242", "url");

#include "dmmsgparser.h"
#include <memory>
#include "person.msg.h"

class CPlayer : public CDMMsgParserSession
    , public CDMDispatcher_db
{
public:
    CPlayer(zmqpp::socket& socket)
        : m_socket(socket)
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
        return m_socket.send(message);
    }

    virtual int Ontb_Person(::google::protobuf::Message& msg, int nLen,
                            const void* pObject)
    {
        ::db::tb_Person* pData = dynamic_cast<::db::tb_Person*>(&msg);
        fmt::print(pData->Utf8DebugString());
        return 0;
    }
public:
    template<class T>
    bool DMAPI SendMsg(T& msg)
    {
        return CDMMsgParserSession::SendMsg(GetMsgID<T>(), msg);
    }
private:
    zmqpp::socket& m_socket;
};

int main(int argc, char* argv[])
{
    DMFLAGS_INIT(argc, argv);
    const std::string endpoint = FLAGS_URL;

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a push socket
    zmqpp::socket_type type = zmqpp::socket_type::client;
    zmqpp::socket socket (context, type);

    // open the connection
    std::cout << "Opening connection to " << endpoint << "..." << std::endl;
    socket.connect(endpoint);

    // send a message
    std::cout << "Sending text and a number..." << std::endl;

    CPlayer oPlayer(socket);
    oPlayer.SessionInit(PROTO_STYLE_DMSTYLE);

    for (;;)
    {

        db::tb_Person tb;

        tb.set_uuid(1);
        tb.set_job(2);

        tb.set_name("tom");
        tb.set_number(1366532956);
        tb.set_email("tom@163.com");
        tb.set_phonetype(db::PhoneType::MOBILE);
        tb.set_money(10000);
        tb.set_cash(10000);

        if (!oPlayer.SendMsg(tb))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    std::cout << "Sent message." << std::endl;
    std::cout << "Finished." << std::endl;
}
