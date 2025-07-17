/*
** EPITECH PROJECT, 2025
** df_int_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "utils.h"

void *df_int_create(const void *v_value)
{
    int *value = NULL;
    int *new_value = NULL;

    if (v_value == NULL)
        return NULL;
    value = (int *) v_value;
    new_value = malloc(sizeof(int));
    if (new_value == NULL)
        return NULL;
    *new_value = *value;
    return new_value;
}
