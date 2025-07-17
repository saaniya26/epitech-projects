/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
