/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (nb > 2 && nb % 2 == 0)
        nb += 1;
    for (; !my_is_prime(nb); nb++);
    return (nb);
}
