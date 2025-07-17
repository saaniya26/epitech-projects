/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-organized-helene.vardanyan
** File description:
** my_strdup.c
*/

#include "hashtable.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *stock = malloc(sizeof(char) * len + 1);

    for (int i = 0; src[i] != '\0'; i++) {
        stock[i] = src[i];
    }
    return stock;
}
