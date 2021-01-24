/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; (s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i]; i++);
    if (s1[i] - s2[i] == 0)
        return 0;
    return (s1[i] - s2[i]) > 0 ? 1 : -1;
}
