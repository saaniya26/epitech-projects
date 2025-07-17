/*
** EPITECH PROJECT, 2024
** Mini_printf
** File description:
** mini_printf.c
*/

#include "myls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar('0' + (nb % 10));
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

int my_switch_case(char s, va_list str)
{
    switch (s) {
        case 'd':
            my_put_nbr(va_arg(str, int));
            break;
        case 'i':
            my_put_nbr(va_arg(str, int));
            break;
        case 's':
            my_putstr(va_arg(str, char *));
            break;
        case 'c':
            my_putchar(va_arg(str, int));
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            return 84;
            break;
    }
}

int mini_printf(const char *format, ...)
{
    int i;
    va_list str;

    va_start(str, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            my_switch_case(format[i + 1], str);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(str);
    return 0;
}
