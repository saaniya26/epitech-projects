/*
** EPITECH PROJECT, 2025
** df_col_desc_check
** File description:
** Cuddle
*/

#include "df_core/df_line.h"
#include "df_core/df_col.h"
#include "df_core/df_types.h"

static column_type_t get_type_from_hierarchy(column_type_t orig_type,
    column_type_t type)
{
    if (orig_type == UNDEFINED || type == UNDEFINED)
        return UNDEFINED;
    if (orig_type == type)
        return orig_type;
    if (orig_type == INT && type == UINT)
        return UINT;
    if (orig_type == UINT && type == INT)
        return INT;
    if (orig_type == FLOAT && (type == INT || type == UINT))
        return type;
    if ((orig_type == INT || orig_type == UINT) && type == FLOAT)
        return FLOAT;
    if (orig_type != STRING && type == STRING)
        return STRING;
    return orig_type;
}

static column_type_t type_uint_int(column_type_t type, bool_t *has_int)
{
    if (has_int == NULL)
        return UNDEFINED;
    if (type == UINT) {
        if (*has_int == TRUE)
            return INT;
        return UINT;
    }
    return type;
}

static column_type_t check(dataframe_column_t *cols,
    column_type_t curr_type, const char *column, bool_t *has_int)
{
    column_type_t new_type = curr_type;
    dataframe_column_t *col = NULL;

    if (cols == NULL || curr_type == UNDEFINED || column == NULL
        || has_int == NULL)
        return UNDEFINED;
    col = df_col_get_name(cols, column);
    if (col == NULL)
        return UNDEFINED;
    for (int i = 0; df_types[i].type != UNDEFINED && df_types[i].type
        != STRING; i++) {
        if (df_can_be_type(col->value, curr_type, df_types[i].type) != TRUE)
            continue;
        new_type = df_types[i].type;
        curr_type = get_type_from_hierarchy(curr_type,
            type_uint_int(new_type, has_int));
    }
    *has_int = (*has_int == FALSE) ? (new_type == INT) : *has_int;
    return curr_type;
}

int df_col_desc_check(dataframe_t *dt, const char *column, bool_t patch)
{
    dataframe_line_t *line = NULL;
    column_type_t new_type = UNDEFINED;
    bool_t has_int = FALSE;

    if (dt == NULL || column == NULL)
        return FUNC_FAILED;
    if (dt->lines == NULL)
        return FUNC_FAILED;
    new_type = df_col_desc_get_name_type(dt->cols_types, column);
    if (new_type == STRING)
        return FUNC_SUCCESS;
    for (line = dt->lines; line != NULL; line = line->next) {
        new_type = check(line->cols, new_type, column, &has_int);
        if (new_type == UNDEFINED)
            return FUNC_FAILED;
    }
    if (patch == TRUE)
        return df_col_promote(dt, new_type, column);
    return FUNC_SUCCESS;
}

int df_col_desc_check_global(dataframe_t *dt, bool_t patch)
{
    dataframe_col_desc_t *desc = NULL;

    if (dt == NULL)
        return FUNC_FAILED;
    desc = dt->cols_types;
    if (desc == NULL)
        return FUNC_FAILED;
    for (; desc != NULL; desc = desc->next)
        if (df_col_desc_check(dt, desc->column_name, patch) == FUNC_FAILED)
            return FUNC_FAILED;
    return FUNC_SUCCESS;
}
