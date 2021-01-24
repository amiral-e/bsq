/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_int_len.c
*/

int my_intlen(int nb)
{
    int i;

    for (; nb; nb /= 10, i++);
    return (i);
}