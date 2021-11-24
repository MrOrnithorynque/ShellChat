/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_client_data.cpp
**   Get username and color of the user.
*/

#include "client.hpp"

void shellchat::User::getUserData(void)
{
	getUsername();
	getUserColor();
}