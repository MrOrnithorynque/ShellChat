#include <iostream>
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