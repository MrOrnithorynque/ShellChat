/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_user_color.cpp
**   Ask what color do the user want and if he don't choose, the color is random.
*/

#include <iostream>
#include <cstring>

#include "client.hpp"

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