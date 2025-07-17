/*
** EPITECH PROJECT, 2025
** df_string_string
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "utils.h"

char *df_string_string(const void *value)
{
    char *output = NULL;

    if (value == NULL)
        return NULL;
    output = (char *) value;
    return my_strdup(output);
}
