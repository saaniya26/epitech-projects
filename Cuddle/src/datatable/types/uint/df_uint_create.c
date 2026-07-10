/*
** EPITECH PROJECT, 2025
** df_uint_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "utils.h"

void *df_uint_create(const void *v_value)
{
    uint_t *value = NULL;
    uint_t *new_value = NULL;

    if (v_value == NULL)
        return NULL;
    value = (uint_t *) v_value;
    new_value = malloc(sizeof(uint_t));
    if (new_value == NULL)
        return NULL;
    *new_value = *value;
    return new_value;
}
