/*
** EPITECH PROJECT, 2025
** df_convert_value
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

static int create_new_type_desc(dataframe_col_desc_t **col_desc,
    const char *string, const char *col_name)
{
    dataframe_col_desc_t *new_desc = NULL;

    if (col_desc == NULL)
        return FUNC_FAILED;
    new_desc = df_col_desc_create(df_id_value(string), my_strdup(col_name));
    if (new_desc == NULL)
        return FUNC_FAILED;
    if (df_col_desc_chain(col_desc, new_desc) == FUNC_FAILED)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

dataframe_col_desc_t *df_get_types(dataframe_t *dt, const char **data)
{
    dataframe_col_desc_t *col_desc = NULL;

    if (dt == NULL || data == NULL)
        return NULL;
    for (int i = 0; i < my_tablen((const void **) data); i++) {
        if (create_new_type_desc(&col_desc, data[i], dt->initial_header[i])
            == FUNC_FAILED)
            return NULL;
    }
    return col_desc;
}
