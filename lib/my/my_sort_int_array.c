/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int tmp = 0;

    for (int i = 0; i < size; i++) {
        if (i >= 1 && (array[i] < array[i - 1])) {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            i = 0;
        }
    }
}
