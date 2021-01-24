/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** my_str_islower
*/

int my_strcmp(char const *s1, char const *s2);

int my_str_islower(char const *str)
{
    if (my_strcmp("", str) == 0)
        return (1);
    for (int i = 0; str[i]; i++)
        if (!('a' <= str[i] <= 'z'))
            return (0);
    return (1);
}
