/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** my_str_isnum
*/

int my_strcmp(char const *s1, char const *s2);

int my_str_isnum(char const *str)
{
    if (my_strcmp("", str) == 0)
        return (1);
    for (int i = 0; str[i]; i++)
        if (!('0' <= str[i] <= '9'))
            return (0);
    return (1);
}
