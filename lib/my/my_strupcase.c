/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    return str;
}
