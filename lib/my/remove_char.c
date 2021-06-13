/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** remove_char
*/

#include "my.h"

char *remove_char(char *str, char c)
{
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            str = offset_array(str, i);
            str = remove_char(str, c);
        }
    }

    return str;
}