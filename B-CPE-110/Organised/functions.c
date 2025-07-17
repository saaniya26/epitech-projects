/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** my_putchar.c
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *temp = malloc(sizeof(char) * len + 1);

    for (int i = 0; src[i] != '\0'; i++)
        temp[i] = src[i];
    return temp;
}

int my_strcmp(char const *str, char const *src)
{
    int i = 0;

    while ((str[i] == src[i]) && str[i] && src[i]) {
        i++;
    }
    return (str[i] - src[i]);
}
