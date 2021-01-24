/*
** EPITECH PROJECT, 2020
** my_is_prio.c
** File description:
** my_is_prio
*/

int my_is_prio(char c)
{
    if (c == '*' || c == '/' || c == '%')
        return (0);
    return (1);
}