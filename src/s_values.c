/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** s_values.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

void set_sizes(values_t *val)
{
    val->size_s = val->cl * (val->cc + 1);
    val->size_c = (int)val->fileStat.st_size - my_intlen(val->cl) - 1;
}

void set_things(values_t *values, char **av)
{
    values->fd = open(av[1], O_RDONLY);
    values->buffer = malloc(sizeof(char) * values->fileStat.st_size);
    values->size = read(values->fd, values->buffer, values->fileStat.st_size);
}