/*
** EPITECH PROJECT, 2025
** df_create_value
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_types.h"
#include "utils.h"

void *df_create_value(const void *value, column_type_t type)
{
    if (value == NULL || type == UNDEFINED)
        return NULL;
    for (int i = 0; df_types[i].type != UNDEFINED; i++)
        if (df_types[i].type == type &&
            df_types[i].create_f != NULL)
            return df_types[i].create_f(value);
    return NULL;
}
