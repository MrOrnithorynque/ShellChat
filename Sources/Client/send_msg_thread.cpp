/*
**
*/

#include <iostream>
#include <cstring>

#include "client.hpp"
#include "my_cpp.hpp"

void shellchat::send_msg_thread(net::Client *Client, shellchat::UserData_t *MyClientData)
{
    std::string user_input;
    char msg[200];

    while (true)
    {
        std::cout << "> ";
        std::cin >> user_input;

        if (user_input.length() > 200)
        {
            std::cout << "message above 200 characters are forbiden\n.";
        } // else command
        else if (user_input.compare("exit") == 0)
        {
            bzero(msg, 200);
            
            break;
        }
        else
        {
            strncpy(MyClientData->client_msg, user_input.c_str(), 200);
            send(Client->ClientData.socket_client, MyClientData, sizeof(MyClientData), 0);
            bzero(msg, 200);
        }
    }
}