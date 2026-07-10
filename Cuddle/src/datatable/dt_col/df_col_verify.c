/*
** EPITECH PROJECT, 2025
** df_col_verify
** File description:
** Cuddle
*/

#include <stdio.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_col.h"
#include "df_core/df_types.h"
#include "utils.h"

static int get_len(char **tab)
{
    int len = 0;

    for (; tab[len] != NULL; len++)
        if (tab[len][0] == '\n')
            break;
    return len;
}

int df_col_verify(dataframe_t *dt, char **args)
{
    column_type_t type = UNDEFINED;
    int args_len = 0;

    if (dt == NULL || args == NULL)
        return FUNC_FAILED;
    args_len = get_len(args);
    if (args_len <= 0)
        return FUNC_FAILED;
    if (dt->nb_columns != args_len)
        return FUNC_FAILED;
    for (int i = 0; i < args_len; i++) {
        type = df_id_value(args[i]);
        if (type == UNDEFINED)
            return FUNC_FAILED;
        if (type != df_col_desc_get_type(dt->cols_types, i))
            return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}
