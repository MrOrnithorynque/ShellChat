/*
** SHELLCHAT PROJECT NOVEMBER 2021
*/

#include <iostream>
#include <stdlib.h>

#include "server.hpp"

static void get_host_ip(const char *IP_ADRESS)
{
	// cmd("hostname -I");
	return;
}

static void generate_port(const unsigned int *PORT)
{
	unsigned int test_port = 1;

	for ( ; /*test if port valid*/ ; ++test_port);
	*PORT = test_port;
}

void shellchat::host_settings(shellchat::Host.Data_t *HostData)
{
	std::string user_input;

	std::cout << "Enter your ip adress (write it like that : \"x.x.x.x\") :\n";
	std::getline(std::cin, user_input);

	if (user_input[0] == '\0')
	{
		get_host_ip(HostData->IP_ADRESS);
	}
	else
	{
		HostData->IP_ADRESS = user_input.c_str;
	}

	std::cout << "Enter the port of your server (Default is random) :\n";
	std::getline(std::cin, user_input);
	if (user_input[0] == '\0')
	{
		generate_port(&HostData->PORT);
	}
	else
	{
		// HostData->PORT = (unsigned int)(my_cpp::get_integer(user_input.c_str));
	}
}