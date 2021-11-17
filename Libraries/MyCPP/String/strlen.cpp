/*
** MYCPP library - strlen from string
*/

#include "MYCPP/string.hpp"

unsigned int my_cpp::strlen(const char *str)
{
	const char *char_ptr;

	for (char_ptr = str; *char_ptr ; ++char_ptr);

	return *char_ptr == '\0' ? (unsigned int)(char_ptr - str) : 0;
}