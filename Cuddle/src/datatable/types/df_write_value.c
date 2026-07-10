/*
** EPITECH PROJECT, 2025
** df_write_value
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_types.h"
#include "utils.h"

int df_write_value(dataframe_column_t *col, FILE *file)
{
    if (col == NULL || file == NULL)
        return FUNC_FAILED;
    if (col->col_descriptor == NULL)
        return FUNC_FAILED;
    for (int i = 0; df_types[i].type != UNDEFINED; i++)
        if (df_types[i].type == col->col_descriptor->type &&
            df_types[i].write_f != NULL)
            return df_types[i].write_f(col->value, file);
    return FUNC_FAILED;
}
