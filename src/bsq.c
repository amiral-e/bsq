/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** test.c
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "my.h"
#include <stdio.h>

int add_array(values_t *val, int i)
{
    if (val->buffer[i] == '.')
        return 1;
    else if (val->buffer[i] == 'o')
        return 0;
    else
        return (84);
}

int make_array(values_t *val)
{
    int i = 0;
    int j = 0;

    val->arr = malloc(sizeof(int *) * (val->cl + 1));
    for (; i < val->cl; i++)
        val->arr[i] = malloc(sizeof(int) * (val->cc + 1));
    for (i = 0; val->buffer[i] != '\n'; i++);
    for (i += 1; j < (val->cl); j++, i++)
        for (int j2 = 0; j2 < (val->cc); j2 += 1, i += 1) {
            val->arr[j][j2] = add_array(val, i);
            if (val->arr[j][j2] == 84)
                return (84);
        }
    return (0);
}

void calc_arr(values_t *val, int j, int j2)
{
    if (val->arr[j][j2 - 1] < val->arr[j - 1][j2 - 1])
        if (val->arr[j][j2 - 1] < val->arr[j - 1][j2])
            val->arr[j][j2] = (val->arr[j][j2] + val->arr[j][j2 - 1]);
        else
            val->arr[j][j2] = (val->arr[j][j2] + val->arr[j - 1][j2]);
    else
        if (val->arr[j - 1][j2 - 1] < val->arr[j - 1][j2])
            val->arr[j][j2] = (val->arr[j][j2] + val->arr[j - 1][j2 - 1]);
        else
            val->arr[j][j2] = (val->arr[j][j2] + val->arr[j - 1][j2]);
}

void alg_bsq(values_t *val)
{
    int j = 1;
    int j2 = 1;

    val->size = 0;
    for (; j < val->cl; j += 1, j2 = 0)
        for (; j2 < val->cc; j2 += 1)
            if (val->arr[j][j2] == 1)
                calc_arr(val, j, j2);
    for (j = 0, j2 = 0; j < val->cl; j += 1, j2 = 0)
        for (; j2 < val->cc; j2 += 1)
            if (val->arr[j][j2] > val->size) {
                val->size = val->arr[j][j2];
                val->posy = j;
                val->posx = j2;
            }
    m_disp_buffer(val);
}

int main(int ac, char **av)
{
    values_t val;

    if (ac != 2)
        return (errors(0));
    if (stat(av[1], &val.fileStat) < 0 || open(av[1], O_RDONLY) == -1)
        return (errors(1));
    set_things(&val, av);
    if (check_read(&val) || be_sure_rmap(&val) ||
        make_array(&val) == 84)
        return (errors(1));
    val.buffer += my_intlen(val.cl) + 1;
    alg_bsq(&val);
    close(val.fd);
    return (0);
}