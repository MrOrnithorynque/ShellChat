/*
** SHELLCHAT PROJECT NOVEMBER 2021
** error_handling.cpp :
**   Check if given arguments are corrects
*/

// #include "MYCPP/string.hpp"
#include "server.hpp"

static void nb_args(int argc)
{
	if (argc > 3)
	{
		//my_cpp::put_error("error: Wrong number of arguments.\n");
		exit(-1);
	}
}

void shellchat::error_handling(int argc, char **argv)
{
	nb_args(argc);
	return;
}

/*
** ALL FUNCTIONS SHOULD BE INLINE
*/