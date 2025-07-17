/*
** EPITECH PROJECT, 2024
** Repos
** File description:
** mystrcat
*/

#include "myls.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strcat(char const *a, char const *b)
{
    int i = 0;
    int j = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));

    while (a[i] != '\0') {
        dest[i] = a[i];
        i++;
    }
    while (b[j] != '\0') {
        dest[i] = b[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
