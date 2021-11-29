/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_user_msg.cpp
**   Get the message given in the stdin.
*/

#include <iostream>
#include <cstring>

#include "client.hpp"

void shellchat::User::getUserMsg(void)
{
	std::string user_input;

	std::cout << "> ";
    std::getline(std::cin, user_input);

	if (user_input.length() > MAX_MSG_LENGTH)
    {
        std::cout << "message above " << MAX_MSG_LENGTH <<" characters are forbiden.\n";
        getUserMsg();
    } // else command
    else if (user_input.compare("exit") == 0)
    {
        bzero(UserData.user_msg, MAX_MSG_LENGTH);
        return;;
    }
    else
    {
        strcpy(UserData.user_msg, user_input.c_str());
	}
}