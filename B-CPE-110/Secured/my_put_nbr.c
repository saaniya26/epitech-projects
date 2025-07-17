/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** my_put_nbr.c
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}

int my_put_nbr_short(int nb)
{
    short int num = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}

int my_put_nbr_long(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}
