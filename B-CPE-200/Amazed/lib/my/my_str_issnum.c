/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** Day 6, Task 13
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

bool_t my_str_issnum(const char *str)
{
    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && i == 0)
            continue;
        if ((str[i] < '0') || (str[i] > '9'))
            return FALSE;
    }
    return TRUE;
}
