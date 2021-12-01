/*
** SHELLCHAT PROJECT NOVEMBER 2021
** bind.cpp
**   Bind server.
*/

#include "server.hpp"

void shellchat::Host::bindTo(void)
{
	net::check(bind(Server.ServerData.socket_server,
					(SOCKADDR *) &Server.ServerData.addr_server,
					sizeof(Server.ServerData.addr_server)), \
                "Bind error.\n");
}