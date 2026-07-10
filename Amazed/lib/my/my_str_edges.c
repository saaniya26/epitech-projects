/*
** EPITECH PROJECT, 2025
** my_str_edges
** File description:
** libmy
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t my_str_edges(const char *str, const char start, const char end)
{
    int len = 0;

    if (str == NULL || start == '\0' || end == '\0')
        return FALSE;
    len = my_strlen(str);
    if (len <= 0)
        return FALSE;
    if (str[0] != start)
        return FALSE;
    if (str[len - 1] != end)
        return FALSE;
    return TRUE;
}
