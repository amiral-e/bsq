/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** check.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"

int errors(int c)
{
    if (c == 0)
        my_puterror("Usage : ./bsq map\n");
    else if (c == 1)
        my_puterror("Something went wrong with map\n");
    else
        my_puterror("usage : ./bsq file\n");
    return (84);
}

int be_sure_rmap(values_t *val)
{
    int i = 0;

    val->cl = my_getnbr(val->buffer);
    if (val->cl <= 0 || !val->cl)
        return (1);
    for (; '0' <= val->buffer[i] && val->buffer[i] <= '9'; i++);
    if (!val->buffer[i] || !val->buffer[i + 1] ||
        (val->buffer[i + 1] != 'o' && val->buffer[i + 1] != '.'))
        return (1);
    for (i += 1, val->cc = 0; val->buffer[i] && val->buffer[i] != '\n'; i++,
        val->cc++);
    for (i += 1, val->ccb = 0; val->buffer[i] && val->buffer[i] != '\n'; i++,
        val->ccb++);
    set_sizes(val);
    if ((val->cl > 1 && val->cc != val->ccb) || val->size_s != val->size_c)
        return (1);
    return (0);
}

int check_read(values_t *val)
{
    if (val->size < my_strlen(val->buffer) ||
        val->size == my_strlen(val->buffer))
        return (0);
    close(val->fd);
    return (1);
}