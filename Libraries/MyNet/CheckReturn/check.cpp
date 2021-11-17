/*
**
*/

#include <iostream>

#include "network.hpp"

void net::check(int return_value, const char *error_msg)
{
    if (return_value < 0)
    {
        std::cerr << "\033[31m" << error_msg << "\033[0m" << std::endl;

        exit(EXIT_FAILURE);
    }
}
