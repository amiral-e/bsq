/*
** EPITECH PROJECT, 2020
** my_is_alphanum.c
** File description:
** my_is_alphanum
*/

int my_is_alphanum(char c)
{
    if (('0' <= c && c <= '9') ||
        ('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z'))
        return (1);
    return (0);
}
