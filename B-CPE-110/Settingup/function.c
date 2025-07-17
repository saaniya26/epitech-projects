/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** my_putchar.c
*/

#include "settingup.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

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

int pattern_index(int k, int len)
{
    if (k == len) {
        k = 0;
    }
    return k;
}

int count_col(square_t *square)
{
    int i;
    int count = 0;

    for (i = 0; square->map[0][i] != '\0'; i++) {
        count++;
    }
    return count;
}
