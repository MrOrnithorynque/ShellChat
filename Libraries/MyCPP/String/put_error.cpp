#include <iostream>

#include "MYCPP/string.hpp"

void my_cpp::put_error(char *error_msg, my_cpp::COLOR_FLAG color /*= my_cpp::RED*/)
{
	std::cout << color << error_msg << "\033[0m";
}