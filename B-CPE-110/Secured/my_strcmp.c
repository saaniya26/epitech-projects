/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** my_strcmp.c
*/

#include "hashtable.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
