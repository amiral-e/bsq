/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;
    int j = 0;

    for (; src[i] != '\0'; i++);
    if (n > i) {
        for (; j < n; j++)
            dest[j] = src[j];
        dest[j++] = src[j++];
    }
    else
        for (int j = 0; j < n; j++)
            dest[j] = src[j];
    return (dest);
}
