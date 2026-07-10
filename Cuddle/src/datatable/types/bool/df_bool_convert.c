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

void *df_bool_convert(const char *string)
{
    const char *allowed_true[] = {"true",
        "True", "TRUE", NULL};
    const char *allowed_false[] = {"false",
        "False", "FALSE", NULL};
    bool new_bool = false;
    bool *value = NULL;

    if (string == NULL)
        return NULL;
    value = malloc(sizeof(bool));
    if (value == NULL)
        return NULL;
    if (my_isin(string, allowed_true) == TRUE)
        new_bool = true;
    if (my_isin(string, allowed_false) == TRUE)
        new_bool = false;
    *value = new_bool;
    return value;
}
