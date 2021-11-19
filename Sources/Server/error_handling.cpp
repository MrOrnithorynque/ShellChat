/*
** SHELLCHAT PROJECT NOVEMBER 2021
** error_handling.cpp :
**   Check if given arguments are corrects
*/

// #include "MYCPP/string.hpp"
#include "server.hpp"

static void nb_args(int const argc)
{
	if (argc > 3)
	{
		//my_cpp::put_error("error: Wrong number of arguments.\n");
		exit(-1);
	}
}

static void check_args(int const argc, char **argv, shellchat::Host.Data_t *HostData)
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
		{
			// print_help();
			exit(0);
		}
		strcpy(HostData->IP_ADRESS, argv[1]);
		// HostData->PORT = (int)(my_cpp::get_integer(argv[2]));
	}
	// host_setting(HostData);
}

void shellchat::error_handling(int const argc, char **argv, shellchat::Host.Data_t *HostData)
{
	nb_args(argc);
	check_args(argc, argv, HostData);
	return;
}

/*
** ALL FUNCTIONS SHOULD BE INLINE
*/