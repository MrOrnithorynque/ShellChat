/*
** SHELLCHAT PROJECT NOVEMBER 2021
** send_user_msg.cpp
**   Send the message given in the stdin.
*/

#include <iostream>

#include "client.hpp"

void shellchat::User::sendUserMsg(void)
{
	send(Client.ClientData.socket_client, &UserData, sizeof(UserData), 0);
    bzero(UserData.user_msg, MAX_MSG_LENGHT);
}