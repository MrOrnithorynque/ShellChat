/*
** SHELLCHAT PROJECT NOVEMBER 2021
** get_client_data.cpp
**   Get username and color of the user.
*/

#include <stdlib.h>
#include <cstring>
#include <time.h>

#include "MYCPP/array.hpp"
#include "client.hpp"

const char *r1_name[] =
{
	"turbo",	"negative", 		"unstonk",
	"super", 	"marvelous", 		"tendentious",
	"gay",		"problematic",		"stonk", 
	"chad",		"mr", 				"sigma",
	"beta", 	"alpha", 			NULL
};

const char *r2_name[] =
{
	"gay",		"iq",				"heterosexuality",
	"racism",	"bot",				"marleneshiappa",
	"zizz",		"male",				"platypus",
	"female",	"homosexuality",	NULL
};

// VALGRIND 100 ERROR MUST FIX
char *slct::create_random_username(void)
{
	srand(time(NULL));

	unsigned int name_1 	= rand() % 13; // my_cpp::array_2d_len(r1_name);
	unsigned int name_2 	= rand() % 11; // my_cpp::array_2d_len(r2_name);
	char *random_username 	= (char *)malloc(sizeof(char) * (strlen(r1_name[name_1]) + strlen(r2_name[name_2]) + 2));

	strcat(strcat(strcat(random_username, r1_name[name_1]), "-"), r2_name[name_2]);

	return random_username;
}