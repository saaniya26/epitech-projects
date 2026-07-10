/*
** EPITECH PROJECT, 2025
** df_int_write
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

int df_int_write(void *value, FILE *file)
{
    int len = 0;
    int *val = NULL;
    char *output = NULL;

    if (value == NULL || file == NULL)
        return FUNC_FAILED;
    val = (int *) value;
    len = snprintf(NULL, 0, "%d", *val);
    if (len <= 0)
        return FUNC_FAILED;
    output = malloc(sizeof(char) * (len + 1));
    output[len] = '\0';
    snprintf(output, len + 1, "%d", *val);
    fwrite(output, sizeof(char), my_strlen(output), file);
    free(output);
    return FUNC_SUCCESS;
}
