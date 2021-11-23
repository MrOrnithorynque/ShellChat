/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_client_data.cpp
**   Get username and color of the user.
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>

#include "client.hpp"

void shellchat::User::getUsername(void)
{
	std::string user_input;

	std::cout << "Enter your username (if no username is entered, a random one will be created) :\n";
	std::getline(std::cin, user_input);

	if (user_input[0] == '\0')
	{
		strncpy(UserData.username, shellchat::create_random_username(), 20);
	}
	else if (user_input.length() > 30)
	{
		return;
	}
	else
	{
		strncpy(UserData.username, user_input.c_str(), 20);
	}
}

void shellchat::User::getUserColor(void)
{
	char *user_colors[] = {"white", "red", "yellow", "blue", "purple", NULL};
	std::string user_input;

	std::cout << UserData.username << ", what color do you want to be {white, red, yellow, blue, purple} ? \nBy default it is random.\n";
	std::getline(std::cin, user_input);

	for (size_t i = 0; i < 5; ++i)
	{
		if (user_input[0] == '\0')
		{
			user_colors[rand() % 4];
			return;
		}
		else if (user_input.compare(user_colors[i]) == 0)
		{
			// UserData.color = user_input
			return;
		}
	}
}

void shellchat::User::getUserData(void)
{
	getUsername();
	getUserColor();

	std::cout << "Hello " << UserData.username << " welcome to ShellChat.\n";
}