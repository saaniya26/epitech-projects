/*
** EPITECH PROJECT, 2024
** my_tabchrlen
** File description:
** day 4, task 3
** my_strlen.c
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

int my_tabchrlen(const void **tab, const char to_find)
{
    int i = 0;

    if (tab == NULL)
        return FUNC_FAILED;
    for (i = 0; tab[i] != NULL; i++)
        if (my_strchr((const char *) tab[i], to_find) != NULL)
            break;
    return i;
}
