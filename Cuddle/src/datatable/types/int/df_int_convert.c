/*
** EPITECH PROJECT, 2025
** df_int_convert
** File description:
** Cuddle
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

void *df_int_convert(const char *string)
{
    int *value = NULL;

    if (string == NULL)
        return NULL;
    value = malloc(sizeof(int));
    if (value == NULL)
        return NULL;
    *value = atoi(string);
    return value;
}
