/*
**
*/

#include <iostream>
#include <cstring>

#include "shellchat.hpp"
#include "client.hpp"

void shellchat::recv_msg_thread(shellchat::User *User)
{
    int recv_value;

    while (true)
    {
        recv_value = recv(User->Client.ClientData.socket_client, &User->UserData, sizeof(User->UserData), 0);

        if (recv_value > 0)
        {
            std::cout << User->UserData.username << " : " << User->UserData.client_msg << std::endl;
        }
        else if (recv_value == 0)
        {
            break;
        }

        // memset(&msg, 0, sizeof(msg));
    }
}