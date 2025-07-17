/*
** EPITECH PROJECT, 2025
** df_string_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

void *df_string_create(const void *v_value)
{
    char *value = NULL;
    char *new_value = NULL;

    if (v_value == NULL)
        return NULL;
    value = (char *) v_value;
    new_value = my_strdup(value);
    return new_value;
}
