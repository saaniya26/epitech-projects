/*
** EPITECH PROJECT, 2025
** df_bool_write
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "utils.h"

int df_bool_write(void *value, FILE *file)
{
    bool *bool_val = NULL;
    char *output = NULL;

    if (value == NULL || file == NULL)
        return FUNC_FAILED;
    bool_val = (bool *) value;
    output = *bool_val ? "true" : "false";
    fwrite(output, sizeof(char), my_strlen(output), file);
    return FUNC_SUCCESS;
}
