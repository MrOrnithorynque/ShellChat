#pragma once

#include <vector>

#include "network.hpp"

namespace shellchat
{
	typedef struct ServerData_s
	{

	} ServerData_t;

	void client_thread(net::Client Client);
	void handle_client(net::Server *Server);
	void server_setting(int argc, char **argv);
} // namespace shellchat

typedef struct ServerData_s
{

} ServerData_t;

void client_thread(net::Client Client);
void handle_client(net::Server *Server);
void server_setting(int argc, char **argv);