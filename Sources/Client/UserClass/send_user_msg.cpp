/*
** SHELLCHAT PROJECT NOVEMBER 2021
** send_user_msg.cpp
**   Send the message given in the stdin.
*/

#include <iostream>

#include "client.hpp"

void slct::User::sendUserMsg(void)
{
	send(Client.ClientData.socket_client, &UserData, sizeof(slct::User::Data_t), 0);
}