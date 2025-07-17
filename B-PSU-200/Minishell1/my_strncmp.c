/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int compare_res = 0;

    if (s1 == NULL || s2 == NULL || n <= 0)
        return 84;
    for (int i = 0; (s1[i] != '\0') && i < n; i++)
        if (s1[i] != s2[i]) {
            compare_res = s1[i] - s2[i];
            break;
        }
    return compare_res;
}

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
