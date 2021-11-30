/*
** SHELLCHAT PROJECT NOVEMBER 2021
** send_user_msg.cpp
**   Send the message given in the stdin.
*/

#include <iostream>

#include "client.hpp"

void shellchat::User::sendUserMsg(void)
{
	std::cout << UserData.username << " : " << UserData.user_msg << std::endl;
	send(Client.ClientData.socket_client, &UserData, sizeof(shellchat::User::Data_t), 0);
}