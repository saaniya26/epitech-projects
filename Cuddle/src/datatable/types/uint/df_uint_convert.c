/*
** EPITECH PROJECT, 2025
** df_uint_convert
** File description:
** Cuddle
*/

#include <stdbool.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

void *df_uint_convert(const char *string)
{
    unsigned int *value = NULL;

    if (string == NULL)
        return NULL;
    value = malloc(sizeof(unsigned int));
    if (value == NULL)
        return NULL;
    *value = strtoul(string, &(char *) {'\0'}, 10);
    return value;
}
