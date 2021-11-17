#pragma once

#include "network.hpp"

namespace shellchat
{
    typedef struct MsgData_s
    {
        char client_msg[200];
        char username[20];
    } MsgData_t;

    const unsigned int MAX_MSG_LENGTH = 200;

    void chat_room(net::Client *Client);
    void get_server_verification(net::Client *Client);
    void recv_msg_thread(net::Client *Client);
    void send_msg_thread(net::Client *Client, MsgData_t *MyClientData);
} // namespace shellchat
