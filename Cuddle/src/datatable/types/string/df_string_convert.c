/*
** EPITECH PROJECT, 2025
** df_string_convert
** File description:
** Cuddle
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

void *df_string_convert(const char *string)
{
    char *value = NULL;

    if (string == NULL)
        return NULL;
    value = my_strdup(string);
    return value;
}
