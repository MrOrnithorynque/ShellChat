/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** remove_white_space
*/

#include "my.h"

char *remove_char_space(char *str, char c)
{
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c && str[i + 1] == c \
        || str[i] == c && str[i + 1] == '\0' \
        || str[i] == c && i == 0) {
            str = offset_array(str, i);
            remove_char_space(str, c);
        }
    }

    return str;
}