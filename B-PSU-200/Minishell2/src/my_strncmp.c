/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strncmp
*/

#include "../include/my.h"

static bool compare_str(const char *str, const char *to_find, int i)
{
    for (int j = 0; to_find[j] != '\0'; j++) {
        if (str[i + j] == '\0' || str[i + j] != to_find[j])
            return false;
    }
    return true;
}

const char *my_strstr(const char *str, const char *to_find)
{
    if (str == NULL || to_find == NULL)
        return NULL;
    if (to_find[0] == '\0')
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[0] && compare_str(str, to_find, i))
            return &str[i];
    }
    return NULL;
}

char *my_strchr(const char *str, const char to_find)
{
    if (str == NULL)
        return NULL;
    if (to_find == '\0')
        return (char *) str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find)
            return (char *) &str[i];
    }
    return NULL;
}

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
