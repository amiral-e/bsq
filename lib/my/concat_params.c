/*
** EPITECH PROJECT, 2020
** concat_params.c
** File description:
** concat_params
*/

#include <stddef.h>
#include <stdlib.h>

char *concat_params(int ac, char **av)
{
    int size = 0;
    int sizebck = 0;
    char *dest = NULL;

    for (int i = 0; i < ac; i++)
        for (int j = 0; av[i][j]; j++, size++);
    size += (ac - 1);
    dest = malloc(sizeof(char) * size);
    if (dest == NULL)
        return (NULL);
    for (int i = 0; i < ac && sizebck < size; i++, sizebck++) {
        for (int j = 0; av[i][j] && sizebck < size; j++, sizebck++)
            dest[sizebck] = av[i][j];
        dest[sizebck] = '\n';
    }
    dest[sizebck - 1] = '\0';
    return (dest);
}
