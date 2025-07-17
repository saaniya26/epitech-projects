/*
** EPITECH PROJECT, 2025
** df_int_string
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *df_int_string(const void *value)
{
    int len = 0;
    int *val = NULL;
    char *output = NULL;

    if (value == NULL)
        return NULL;
    val = (int *) value;
    len = snprintf(NULL, 0, "%d", *val);
    if (len <= 0)
        return NULL;
    output = malloc(sizeof(char) * (len + 1));
    output[len] = '\0';
    snprintf(output, len + 1, "%d", *val);
    return output;
}
