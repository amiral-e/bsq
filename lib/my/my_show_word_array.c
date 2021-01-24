/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** my_show_word_array
*/

void my_putchar(char c);

void my_putstr(char *str);

int my_show_word_array(char * const * tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
