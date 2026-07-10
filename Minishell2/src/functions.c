/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** functions
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
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

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *temp = malloc(sizeof(char) * len + 1);

    for (int i = 0; src[i] != '\0'; i++)
        temp[i] = src[i];
    return temp;
}

void my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    return dest;
}
