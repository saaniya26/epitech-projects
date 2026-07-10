/*
** EPITECH PROJECT, 2025
** df_bool_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

void *df_bool_create(const void *v_value)
{
    bool *value = NULL;
    bool *new_value = NULL;

    if (v_value == NULL)
        return NULL;
    value = (bool *) v_value;
    new_value = malloc(sizeof(bool));
    if (new_value == NULL)
        return NULL;
    *new_value = *value;
    return new_value;
}
