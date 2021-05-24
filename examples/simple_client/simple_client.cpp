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

using namespace std;

int main(int argc, char* argv[])
{
    const string endpoint = "tcp://localhost:4242";

    // initialize the 0MQ context
    zmqpp::context context;

    // generate a push socket
    zmqpp::socket_type type = zmqpp::socket_type::client;
    zmqpp::socket socket (context, type);

    // open the connection
    cout << "Opening connection to " << endpoint << "..." << endl;
    socket.connect(endpoint);

    // send a message
    cout << "Sending text and a number..." << endl;

    for (;;)
    {
        zmqpp::message message;

        db::tb_Person tb;

        tb.set_uuid(1);
        tb.set_job(2);

        tb.set_name("tom");
        tb.set_number(1366532956);
        tb.set_email("tom@163.com");
        tb.set_phonetype(db::PhoneType::MOBILE);
        tb.set_money(10000);
        tb.set_cash(10000);

        message << tb.SerializeAsString();

        if (!socket.send(message))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    cout << "Sent message." << endl;
    cout << "Finished." << endl;
}
