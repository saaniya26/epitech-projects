/*
** EPITECH PROJECT, 2025
** df_bool_convert
** File description:
** Cuddle
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

void *df_float_convert(const char *string)
{
    double *value = NULL;

    if (string == NULL)
        return NULL;
    value = malloc(sizeof(double));
    if (value == NULL)
        return NULL;
    *value = atof(string);
    return value;
}
