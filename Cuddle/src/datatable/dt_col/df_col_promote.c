/*
** EPITECH PROJECT, 2025
** df_col_promote
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_line.h"
#include "df_core/df_col.h"
#include "df_core/df_types.h"
#include "utils.h"

static int promote(dataframe_column_t *col, column_type_t orig_type,
    column_type_t type)
{
    void *old_value = NULL;
    void *temp_value = NULL;

    if (col == NULL)
        return FUNC_FAILED;
    if (df_can_be_type(col->value, orig_type, type) == FALSE)
        return FUNC_FAILED;
    old_value = col->value;
    if (type == STRING) {
        temp_value = df_get_valstring(col->value, orig_type);
        col->value = df_create_value(temp_value, type);
        free(temp_value);
    } else
        col->value = df_create_value(col->value, type);
    free(old_value);
    return FUNC_SUCCESS;
}

int df_col_promote(dataframe_t *dt, column_type_t type, const char *column)
{
    dataframe_line_t *line = NULL;
    dataframe_column_t *col = NULL;
    column_type_t orig_type = UNDEFINED;
    dataframe_col_desc_t *desc = NULL;

    if (dt == NULL || type == UNDEFINED || column == NULL)
        return FUNC_FAILED;
    if (dt->lines == NULL)
        return FUNC_FAILED;
    desc = df_col_desc_get_name(dt->cols_types, column);
    orig_type = desc != NULL ? desc->type : UNDEFINED;
    desc->type = type;
    for (line = dt->lines; line != NULL; line = line->next) {
        col = df_col_get_name(line->cols, column);
        if (col == NULL)
            return FUNC_FAILED;
        if (promote(col, orig_type, type) == FUNC_FAILED)
            return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}
