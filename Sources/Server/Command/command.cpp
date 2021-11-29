/*
** SHELLCHAT PROJECT NOVEMBER 2021
** command.cpp
**   Check if the client sent a command to the server. And if yes, call the desired function.
*/

#include <iostream>
#include <string.h>

#include "MYCPP/array.hpp"
#include "MYCPP/string.hpp"
#include "shellchat.hpp"
#include "server.hpp"
#include "command.hpp"

bool shellchat::command(shellchat::Host *Host, net::Client *Client, shellchat::UserData_s *UserData)
{
	char **user_cmd;
	char *user_msg = strcpy(user_msg, UserData->client_msg);

	if (user_msg[0] == '/')
	{
		// user_msg = my_cpp::offset_array(user_msg, 0, strlen(user_msg));
		// user_cmd = my_cpp::str_to_2d_array(user_msg, " ");

		for (size_t i = 0; i < shellchat::cmd::ALL_CMD_LENGTH; ++i)
		{
			/*
			if (strcmp(shellchat::cmd::all_cmd[i], user_cmd[0]) == 0)
			{
				//shellchat::cmd::all_cmd_function[i]();
				return true;
			}
			*/
		}
		// send to client that he s a bitch and he give you a wrong cmd
	}
	return false;
}