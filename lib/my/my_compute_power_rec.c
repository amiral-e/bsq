/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}
