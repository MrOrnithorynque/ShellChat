#pragma once

namespace shellchat::cmd
{
	const unsigned int ALL_CMD_LENGTH = 2;

	void launch_game(shellchat::Host *Host);
	void pv_msg(shellchat::Host *Host, SOCKET recever_socket);

	/*
	const char *all_cmd[] =
	{
		"game", "pv"
	};

	void(*all_cmd_function[ALL_CMD_LENGTH])(void) =
	{
		launch_game, pv_msg
	};
	*/
} // shellchat::cmd namespace