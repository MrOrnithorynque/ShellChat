#pragma once

namespace shellchat::cmd
{
	const unsigned int ALL_CMD_LENGHT = 2;

	const char *all_cmd[] =
	{
		"game", "pv", NULL
	};

	void(*all_cmd_function[ALL_CMD_LENGHT])(void) =
	{
		launch_game, pv_msg, NULL
	};

	void launch_game(shellchat::Host *Host);
	void pv_msg(shellchat::Host *Host, SOCKET recever_socket);
} // shellchat::cmd namespace