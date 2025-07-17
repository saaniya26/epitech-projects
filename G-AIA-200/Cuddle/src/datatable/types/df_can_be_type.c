/*
** EPITECH PROJECT, 2025
** df_can_be_type
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "df_core/df_types.h"
#include "utils.h"

bool_t df_can_be_type(const void *value, column_type_t original_type,
    column_type_t target_type)
{
    char *string = NULL;
    column_type_t type = UNDEFINED;

    if (value == NULL)
        return FALSE;
    string = df_get_valstring(value, original_type);
    if (string == NULL)
        return FALSE;
    for (int i = 0; df_types[i].type != UNDEFINED && type == UNDEFINED; i++) {
        if (df_types[i].type == target_type && df_types[i].id_f != NULL)
            type = df_types[i].id_f(string) == TRUE ? df_types[i].type
                : UNDEFINED;
        if (type == target_type)
            break;
    }
    free(string);
    return type == target_type;
}
