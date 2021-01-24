/*
** EPITECH PROJECT, 2020
** my_is_operator.c
** File description:
** my_is_operator
*/

int my_is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (0);
    return (1);
}
