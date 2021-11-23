/*
** SHELLCHAT PROJECT NOVEMBER 2021
** error_handling.cpp :
**   Check if given arguments are corrects
*/

// #include "MYCPP/string.hpp"
#include "server.hpp"

static void print_help(void)
{
	std::cout <<
	"This is the server side of ShellChat.\n" <<
	"Usage :\n" <<
		"\t./ShellChat_server [IP_ADRESS] [PORT] [-OPTION]\n" <<
	"\n" <<
	"Options :\n" <<
		"\t-h --help 	Display help.\n" <<
		"\t-a --auto	Find host ip adress and available port.\n" <<
		"\t-s --silent	No sound.\n";
}

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
	if (argc == 2)
	{
		if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
		{
			print_help();
			exit(0);
		}
		else if (strcmp(argv[1], "--auto") == 0 || strcmp(argv[1], "-a") == 0)
		{
			// host_settings(HostData);
			return;
		}
	}
	else if (argc < 2)
	{
		else
		{
			// find ip
		}
		for (size_t i = 0; i < argc; ++i)
		{
			if (strcmp(argv[i], "--silent") == 0 || strcmp(argv[i], "-s") == 0)
			{
				// goes silent;
			}
			else if (strcmp(argv[i], "--auto") == 0 || strcmp(argv[i], "-a") == 0)
			{
				// goes auto;
			}
		}
		// strcpy(HostData->IP_ADRESS, argv[1]);
		// HostData->PORT = (int)(my_cpp::get_integer(argv[2]));
	}
	// host_settings(HostData);
}

void shellchat::error_handling(int const argc, char **argv, shellchat::Host.Data_t *HostData)
{
	nb_args(argc);
	check_args(argc, argv, HostData);
}

/*
** ALL FUNCTIONS SHOULD BE INLINE
*/