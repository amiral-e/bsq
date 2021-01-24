/*
** EPITECH PROJECT, 2020
** my_str_isupper.c
** File description:
** my_str_isupper
*/

int my_strcmp(char const *s1, char const *s2);

int my_str_isupper(char const *str)
{
    if (my_strcmp("", str) == 0)
        return (1);
    for (int i = 0; str[i]; i++)
        if (!('A' <= str[i] <= 'Z'))
            return (0);
    return (1);
}
