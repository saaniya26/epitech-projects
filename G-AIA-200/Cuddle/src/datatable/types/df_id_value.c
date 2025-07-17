/*
** EPITECH PROJECT, 2025
** df_id_value
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

column_type_t df_id_value(const char *string)
{
    column_type_t type = UNDEFINED;

    if (string == NULL)
        return UNDEFINED;
    for (int i = 0; df_types[i].type != UNDEFINED && type == UNDEFINED; i++)
        if (df_types[i].id_f != NULL)
            type = df_types[i].id_f(string) == TRUE
                ? df_types[i].type : UNDEFINED;
    return type;
}
