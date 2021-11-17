/*
**
*/

#include <stdlib.h>

#include "MYCPP/string.hpp"

typedef struct Number_s
{
    short           op;
    int             is_number;
    unsigned int    result;
} Number_t;

static void get_number(Number_t *Number, char *str, int i)
{
    int mult = 1;

    for ( ; str[i + 1] >= '0' && str[i + 1] <= '9'; ++i);
    for ( ; (str[i] >= '0' && str[i] <= '9') && i >= 0; --i)
    {
        Number->result += (str[i] - '0') * mult;
        mult = mult * 10;

        if (Number->result > 2147483647)
        {
            Number->is_number = -1;
        }
    }
}

static void get_number_in_str(Number_t *Number, char *str)
{
    size_t str_len = my_cpp::strlen(str);
 
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            get_number(Number, str, i);
            return;
        }
        else if (str[i] == '-')
        {
            Number->op = -1;
        }
        else
        {
            Number->op = 1;
        }
    }
    Number->is_number = -1;
}

int get_integer(char *str)
{
    Number_t Number = {1, 0, 0};

    get_number_in_str(&Number, str);
    if (Number.is_number == -1)
    {
        return 0; // throw error
    }

    return int(Number.result * Number.op);
}