#include <iostream>

#include "my.hpp"

void my::print_err(std::string error_msg)
{
    std::cerr << "\033[31m" << error_msg << "\033[0m" << "\n";
}