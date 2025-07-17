/*
** EPITECH PROJECT, 2025
** df_float_write
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

int df_float_write(void *value, FILE *file)
{
    int len = 0;
    double *float_val = NULL;
    char *output = NULL;

    if (value == NULL || file == NULL)
        return FUNC_FAILED;
    float_val = (double *) value;
    len = snprintf(NULL, 0, "%f", *float_val);
    if (len <= 0)
        return FUNC_FAILED;
    output = malloc(sizeof(char) * (len + 1));
    output[len] = '\0';
    snprintf(output, len + 1, "%f", *float_val);
    fwrite(output, sizeof(char), my_strlen(output), file);
    free(output);
    return FUNC_SUCCESS;
}
