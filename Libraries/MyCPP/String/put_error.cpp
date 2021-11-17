#include <iostream>

#include "MYCPP/string.hpp"

void put_error(char *error_msg, COLOR_FLAG color = RED)
{
	std::cout << color << error_msg << "\033[0m";
}