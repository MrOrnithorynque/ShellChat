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

    while (!User->stop_chat)
    {
        recv_value = recv(User->Client.ClientData.socket_client, &User->ExternUserData, sizeof(shellchat::User::Data_t), 0);

        if (recv_value > 0)
        {
            std::cout << User->ExternUserData.username << " : " << User->ExternUserData.user_msg << std::endl;
        }
        else if (recv_value == 0)
        {
            break;
        }

        // memset(&msg, 0, sizeof(msg));
    }
}