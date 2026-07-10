/*
** EPITECH PROJECT, 2024
** my_str_isfloat
** File description:
** Day 6, Task 13
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

bool_t my_str_isfloat(const char *str)
{
    int dots = 0;

    if (str == NULL)
        return FALSE;
    for (int i = 0; str[i] != '\0'; i++) {
        if (((str[i] < '0') || (str[i] > '9')) && (str[i] != '.'))
            return FALSE;
        if (str[i] == '.')
            dots++;
    }
    if (dots != 1)
        return FALSE;
    return TRUE;
}
