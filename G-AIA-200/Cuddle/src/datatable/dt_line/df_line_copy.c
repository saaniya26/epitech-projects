/*
** EPITECH PROJECT, 2025
** df_line_copy
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "my.h"
#include "df_core/df_types.h"
#include "df_core/df_col.h"
#include "dataframe.h"
#include "utils.h"

static int copy_data(dataframe_line_t *line, const char *column, int i)
{
    void *value = NULL;
    dataframe_column_t *new_col = NULL;
    dataframe_t *dt = line != NULL ? line->dt : NULL;

    if (line == NULL || dt == NULL || column == NULL || i < 0)
        return FUNC_FAILED;
    if (dt->cols_types == NULL)
        return FUNC_FAILED;
    value = df_convert_value(column, df_col_desc_get_type(dt->cols_types, i));
    new_col = df_col_create(df_col_desc_get(dt->cols_types, i), value);
    if (df_col_chain(&line->cols, new_col) == FUNC_FAILED)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

int df_line_copy_ctl(dataframe_line_t *line, char **cols)
{
    int cols_len = 0;

    if (line == NULL || cols == NULL)
        return FUNC_FAILED;
    if (df_col_verify(line->dt, cols) == FUNC_FAILED)
        return FUNC_FAILED;
    cols_len = my_tablen((const void **) cols);
    for (int i = 0; i < cols_len && cols[i] != NULL; i++)
        if (copy_data(line, cols[i], i) == FUNC_FAILED)
            return FUNC_FAILED;
    return FUNC_SUCCESS;
}
