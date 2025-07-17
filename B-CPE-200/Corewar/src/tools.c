/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-helene.vardanyan
** File description:
** tools.c
*/

#include "../include/my.h"

int swap_oct(int value)
{
    unsigned int v = (unsigned int)value;

    return ((v & 0xFF000000) >> 24)
        | ((v & 0x00FF0000) >> 8)
        | ((v & 0x0000FF00) << 8)
        | ((v & 0x000000FF) << 24);
}

int my_puterror(const char *msg)
{
    write(2, msg, my_strlen(msg));
    return EXIT_FAILURE;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strcmp(char const *str, char const *src)
{
    int i = 0;

    while ((str[i] == src[i]) && str[i] && src[i]) {
        i++;
    }
    return (str[i] - src[i]);
}

void my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
