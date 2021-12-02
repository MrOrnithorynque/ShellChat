/*
**
*/

#include "MYCPP/array.hpp"
#include "MYCPP/string.hpp"

char *my_cpp::rm_white_space(char *str, char c /*= ' '*/)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == c && str[i + 1] == c \
        || str[i] == c && str[i + 1] == '\0' \
        || str[i] == c && i == 0)
        {
            str = my_cpp::offset_array(str, i, my_cpp::strlen(str));
            str = rm_white_space(str, c);
        }
    }

    return str;
}