/*
** EPITECH PROJECT, 2025
** df_string_write
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdbool.h>
#include "my.h"
#include "utils.h"

int df_string_write(void *value, FILE *file)
{
    char *output = NULL;

    if (value == NULL || file == NULL)
        return FUNC_FAILED;
    output = (char *) value;
    fwrite(output, sizeof(char), my_strlen(output), file);
    return FUNC_SUCCESS;
}
