/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** task01 Write a function that allocates memory and copies
** the string given as argument in it.
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int len_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (len_src + 1));

    for (size_t i = 0; src[i] != '\0'; ++i) {
        str[i] = src[i];
    }
    str[len_src] = '\0';

    return str;
}
