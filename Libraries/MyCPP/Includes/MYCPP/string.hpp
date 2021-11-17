#pragma once

typedef const int FLAG;
typedef const char * COLOR_FLAG;

COLOR_FLAG RED 		= "\033[31m";
COLOR_FLAG YELLOW 	= "\033[33m";
COLOR_FLAG BLUE 	= "\033[34m";
COLOR_FLAG PURPLE 	= "\033[35m";

namespace my_cpp
{
	void 			put_error(char *error_msg, COLOR_FLAG color = RED);
	char 			*strdup(char *src);
	char 			*rm_white_space(char *str, char c = ' ');
	char 			**str_to_2d_array(char *str, char *parser, FLAG option = 0);
	unsigned int	strlen(const char *str);
	int 			get_integer(char *str);

	class string;
}