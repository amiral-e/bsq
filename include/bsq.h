/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** bsq.h
*/

#include <sys/stat.h>

#ifndef BSQ_H
#define BSQ_H

typedef struct values_s
{
    struct stat fileStat;
    int fd;
    int posx;
    int posy;
    int size;
    int size_s;
    int size_c;
    int cl;
    int cc;
    int ccb;
    char *buffer;
    int **arr;
} values_t;

int errors(int c);
int be_sure_rmap(values_t *values);
int check_read(values_t *values);

void set_things(values_t *values, char **av);
void set_sizes(values_t *val);
void disp_array(values_t *val);
void m_disp_buffer(values_t *val);

#endif /* BSQ_H */