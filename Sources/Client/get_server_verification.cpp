/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_server_verification.cpp :
**   receve the ping of the serv to check if client is
**   still alive.
*/

#include "client.hpp"

void get_server_verification(net::Client *Client)
{
	int send_value;
	int recv_value = recv(Client->ClientData.socket_client, &send_value, sizeof(int), 0);
}