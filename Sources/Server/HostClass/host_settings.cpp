/*
** SHELLCHAT PROJECT NOVEMBER 2021
** hostSettings.cpp
**   Check if the client sent a command to the server. And if yes, call the desired function.
*/

#include <iostream>
#include <cstring>

#include "server.hpp"

void slct::Host::hostSettings(int flag) //int flag = MANUAL
{
	if (flag == AUTO)
	{
		getHostIp();
		generatePort();

		return;	
	}

	std::string user_input;

	std::cout << "Enter your ip address (write it like that : \"x.x.x.x\") :\n";
	std::getline(std::cin, user_input);

	if (user_input[0] == '\0')
	{
		getHostIp();
	}
	else
	{
		strcpy(HostData.IP_ADDRESS, user_input.c_str());
	}

	std::cout << "Enter the port of your server (Default is random) :\n";
	std::getline(std::cin, user_input);
	if (user_input[0] == '\0')
	{
		generatePort();
	}
	else
	{
		// HostData.PORT = (unsigned int)(my_cpp::get_integer(user_input.c_str));
	}
}