/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf.c
*/

#include "my.h"

int my_switch(char ac, va_list arg)
{
    switch (ac) {
    case 'd':
    case 'i':
        my_put_nbr(va_arg(arg, int));
        break;
    case 's':
        my_putstr(va_arg(arg, char *));
        break;
    case 'c':
        my_putchar(va_arg(arg, int));
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
    va_list arg;

    va_start(arg, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%'){
            my_switch(format[i + 1], arg);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(arg);
}
