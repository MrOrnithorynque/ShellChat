/*
** EPITECH PROJECT, 2021
** B-PSU-101-PAR-1-4-minishell1-louis.obeniche-rousse
** File description:
** my_str_to_array
*/

#include <stdbool.h>
#include "my.h"

static bool char_in_str(char c, char *parser)
{
    for (size_t i = 0; parser[i] != '\0'; ++i) {
        if (parser[i] == c)
            return true;
    }

    return false;
}

static int count_lines(char *str, char *parser)
{
    int nb_lines    = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if ((char_in_str(str[i + 1], parser) && !char_in_str(str[i], parser)) \
        || (!char_in_str(str[i], parser) && str[i + 1] == '\0'))
            nb_lines++;
    }

    return nb_lines;
}

static int count_cols(char *str, char *parser)
{
    int nb_cols     = 0;
    int tmp         = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (i > 0 && !char_in_str(str[i - 1], parser))
            ++tmp;
        if (nb_cols <= tmp)
            nb_cols = tmp;
        if (i > 0 && char_in_str(str[i - 1], parser))
            tmp = 1;
    }

    return nb_cols;
}

static char **parser_str(char **word_array, char *str, char *parser)
{
    int k           = 0;
    int i           = 0;

    for (; char_in_str(str[i], parser); ++i);
    for (; str[i] != '\0';) {
        for (int j = 0; str[i] != '\0' || char_in_str(str[i], parser); ++i) {
            word_array[k][j] = str[i];
            ++j;
            if (char_in_str(str[i + 1], parser) || str[i + 1] == '\0') {
                word_array[k][j] = '\0';
                ++k;
                ++i;
                break;
            }
        }
        for (; char_in_str(str[i], parser); ++i);
    }
    word_array[k] = NULL;
    return word_array;
}

char **my_str_to_array(char *str, char *parser)
{
    int nb_lines    = count_lines(str, parser);
    int nb_cols     = count_cols(str, parser);

    return parser_str(malloc_2d_array(nb_lines, nb_cols), str, parser);
}
