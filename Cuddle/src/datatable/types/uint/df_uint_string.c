/*
** EPITECH PROJECT, 2025
** df_uint_string
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *df_uint_string(const void *value)
{
    int len = 0;
    uint_t *val = NULL;
    char *output = NULL;

    if (value == NULL)
        return NULL;
    val = (uint_t *) value;
    len = snprintf(NULL, 0, "%u", *val);
    if (len <= 0)
        return NULL;
    output = malloc(sizeof(char) * (len + 1));
    output[len] = '\0';
    snprintf(output, len + 1, "%u", *val);
    return output;
}
