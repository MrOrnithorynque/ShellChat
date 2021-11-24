#pragma once

#include "network.hpp"

namespace shellchat
{
	const unsigned short MAX_MSG_LENGTH      = 400;
    const unsigned short MAX_USERNAME_LENGTH = 30;

	typedef struct UserData_s {
        char client_msg[MAX_MSG_LENGTH];
        char username[MAX_USERNAME_LENGTH];
        //my_cpp::COLOR_FLAG color;
        char *color;
    } UserData_t;
}