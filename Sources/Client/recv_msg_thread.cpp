/*
**
*/

#include <iostream>
#include <cstring>

#include "shellchat.hpp"
#include "client.hpp"

void shellchat::recv_msg_thread(net::Client *Client)
{
    shellchat::UserData_t UserData;
    int recv_value;

    while (true)
    {
        recv_value = recv(Client->ClientData.socket_client, &UserData, sizeof(UserData), 0);

        if (recv_value > 0)
        {
            std::cout << UserData.username << " : " << UserData.client_msg << std::endl;
        }
        else if (recv_value == 0)
        {
            break;
        }

        // memset(&msg, 0, sizeof(msg));
    }
}