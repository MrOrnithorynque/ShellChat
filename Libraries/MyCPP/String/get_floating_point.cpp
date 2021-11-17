/*
**
*/

#include <stdlib.h>

#include "MYCPP/string.hpp"

typedef struct Number_s
{
	bool 	comma;
    short   op;
    int     is_number;
    char    *str_number;
    double  result;
} Number_t;

static bool correct_comma(bool *is_comma_checked, char *str, int i)
{
	if (str[i + 1] == '.')
	{
		*is_comma_checked = true;

		if (str[i + 2] >= '0' && str[i + 2] <= '9')
			return true;
		else
			return false;
	}

	return true;
}

static void store_number(Number_t *Number, char *str, int i)
{
	bool is_comma_checked = false;

	for (size_t j = i, k = 0 ; str[j] == '.' || (str[j] >= '0' && str[j] <= '9'); ++j, ++k)
    {
		if (!is_comma_checked)
		{
			Number->comma = correct_comma(&is_comma_checked, str, j);
		}

        Number->str_number[k] = str[j];

		if (!Number->comma)
		{
			break;
		}
    }
}

static void get_number(Number_t *Number, char *str, int i)
{
    int mult = 1;

    for (; str[i + 1] >= '0' && str[i + 1] <= '9'; ++i);
    for (; (str[i] >= '0' && str[i] <= '9') && i >= 0; --i)
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

float get_floating_point(char *str)
{
    Number_t Number = {1, 0, 0, 0};

    get_number_in_str(&Number, str);
    if (Number.is_number == -1)
    {
        free(Number.str_number);
        return 0; // throw error
    }

    return float(Number.result * Number.op);
}