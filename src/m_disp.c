/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** disp.c
*/

#include "my.h"
#include "bsq.h"
#include <unistd.h>

void disp_array(values_t *val)
{
    for (int j = 0; j < (val->cl); j++) {
        for (int i = 0; i < (val->cc); i++) {
            if (val->arr[j][i] == 1)
                my_putchar('.');
            else if (val->arr[j][i] == 0)
                my_putchar('o');
            else
                my_putchar(val->arr[j][i] + '0');
        }
        my_putchar('\n');
    }
}

void m_disp_buffer(values_t *val)
{
    int posx = val->posx - (val->size - 1);
    int posy = val->posy - (val->size - 1);

    val->cc += 1;
    val->posy += 1;
    for (int pos = posx + (posy * val->cc); posy <= val->posy; posy++) {
        for (int j = posx; j <= val->posx; j++, pos++)
            val->buffer[pos] = 'x';
        pos = posx + (posy * val->cc);
    }
    write(1, val->buffer, val->fileStat.st_size - (my_intlen(val->cl) + 2));
}