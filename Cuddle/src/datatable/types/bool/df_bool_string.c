/*
** EPITECH PROJECT, 2025
** df_bool_string
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "utils.h"

char *df_bool_string(const void *value)
{
    bool *bool_val = NULL;
    char *output = NULL;

    if (value == NULL)
        return NULL;
    bool_val = (bool *) value;
    output = *bool_val ? my_strdup("true") : my_strdup("false");
    return output;
}
