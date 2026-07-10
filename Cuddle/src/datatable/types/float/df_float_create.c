/*
** EPITECH PROJECT, 2025
** df_double_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "utils.h"

void *df_float_create(const void *v_value)
{
    double *value = NULL;
    double *new_value = NULL;

    if (v_value == NULL)
        return NULL;
    value = (double *) v_value;
    new_value = malloc(sizeof(double));
    if (new_value == NULL)
        return NULL;
    *new_value = *value;
    return new_value;
}
