/*
** SHELLCHAT PROJECT NOVEMBER 2021
** listen.cpp
**   listen server.
*/

#include "server.hpp"

void shellchat::host::listen(void)
{
	net::check(listen(Server.ServerData.socket_server, MAX_CLIENTS), \
                "Listen error.\n");
}