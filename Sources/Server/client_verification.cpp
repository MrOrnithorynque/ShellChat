/*
** SHELLCHAT PROJECT NOVEMBER 2021
*/

#include <unistd.h>
#include <vector>

#include "server.hpp"

void client_verification(std::vector<net::Client> AllClients_p) // ptr to vector
{
	size_t size = AllClients_p.size();
	int ping = 1;
	int send_value;

	for (size_t i = 0; i < size; ++i)
	{
		send_value = send(AllClients_p[i].ClientData.socket_client, &ping, sizeof(int), 0);

		if (send_value == -1)
		{
			AllClients_p[i] = AllClients_p[size - 1];
			AllClients_p.pop_back();
		}
		sleep(100000);
	}
}