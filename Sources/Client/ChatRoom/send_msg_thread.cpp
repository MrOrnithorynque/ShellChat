/*
**
*/

#include <iostream>
#include <cstring>

#include "shellchat.hpp"
#include "client.hpp"
#include "my_cpp.hpp"

void shellchat::send_msg_thread(shellchat::User *User)
{
    std::string user_input;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, user_input);

        if (user_input.length() > 400)
        {
            std::cout << "message above 200 characters are forbiden.\n";
        } // else command
        else if (user_input.compare("exit") == 0)
        {
            bzero(User->UserData.user_msg, 200);

            break;
        }
        else
        {
            strncpy(User->UserData.user_msg, user_input.c_str(), 200);
            User.send()
            //send(User->Client.ClientData.socket_client, &User->UserData, sizeof(User->UserData), 0);
            bzero(User->UserData.user_msg, 200);
        }

        usleep(500000);
    }
}