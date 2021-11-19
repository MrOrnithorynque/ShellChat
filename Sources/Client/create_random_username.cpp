/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_client_data.cpp
**   Get username and color of the user.
*/

#include <stdlib.h>

#include "client.hpp"

const char *r1_name[] = {"turbo", "negative", "unstonk", "super", "marvelous", "tendentious", "gay", NULL};
const char *r2_name[] = {"gay", "iq", "heterosexuality", "racism", "bot", "marleneshiappa", "zizz", NULL};

char *shellchat::create_random_username(void)
{
	int name_1 = rand() % 7;
	int name_2 = rand() % 7;
	char *random_username = (char *)malloc(sizeof(char) * (strlen(r1_name[name_1]) + strlen(r2_name[name_2]) + 2));

	strcat(strcat(strcat(random_username, r1_name[name_1]), "-"), r2_name[name_2]);

	return random_username;
}