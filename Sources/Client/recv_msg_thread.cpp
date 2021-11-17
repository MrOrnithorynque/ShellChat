/*
**
*/

#include <pthread.h>
#include <iostream>
#include <cstring>

#include "my.hpp"
#include "client.hpp"

void recv_msg_thread(net::Client *Client)
{
    MsgData_t MsgData;
    char msg[MAX_MSG_LENGTH];
    int recv_value;

    while (true)
    {
        recv_value = recv(Client->ClientData.socket_client, &MsgData, sizeof(MsgData), 0);

        if (recv_value > 0)
        {
            std::cout << MsgData.username << " : " << MsgData.client_msg << std::endl;
        }
        else if (recv_value == 0)
        {
            break;
        }

        memset(msg, 0, sizeof(msg));
    }
}