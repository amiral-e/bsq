/*
** EPITECH PROJECT, 2020
** my_str_is_numop.c
** File description:
** my_str_is_numop
*/

#include <stdbool.h>

bool my_str_is_numop(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i = 1;
    for (; str[i]; i++)
        if (!('0' <= str[i] && str[i] <= '9'))
            return (false);
    return (true);
}