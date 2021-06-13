/*
** EPITECH PROJECT, 2021
** lib/my
** File description:
** offset_array
*/

#include "my.h"

char *offset_array(char *str, size_t offset)
{
    char *tmp = malloc(sizeof(char) * my_strlen(str));
    size_t j = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (i == offset)
            ++i;
        tmp[j] = str[i];
        ++j;
    }
    tmp[j] = '\0';

    return tmp;
}

char **offset_2d_array(char **tab, size_t offset)
{
    for (; tab[offset + 1] != NULL; ++offset) {
        free(tab[offset]);
        tab[offset] = my_strdup(tab[offset + 1]);
    }
    free(tab[my_tablen((void **)tab)]);
    tab[offset] = NULL;

    return tab;
}
