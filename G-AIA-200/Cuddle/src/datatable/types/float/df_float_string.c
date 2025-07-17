/*
** EPITECH PROJECT, 2025
** df_float_string
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *df_float_string(const void *value)
{
    int len = 0;
    double *float_val = NULL;
    char *output = NULL;

    if (value == NULL)
        return NULL;
    float_val = (double *) value;
    len = snprintf(NULL, 0, "%f", *float_val);
    if (len <= 0)
        return NULL;
    output = malloc(sizeof(char) * (len + 1));
    output[len] = '\0';
    snprintf(output, len + 1, "%f", *float_val);
    return output;
}
