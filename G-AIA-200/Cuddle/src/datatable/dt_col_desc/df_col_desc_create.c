/*
** EPITECH PROJECT, 2025
** df_col_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

dataframe_col_desc_t *df_col_desc_create(column_type_t type, char *name)
{
    dataframe_col_desc_t *new_col_desc = NULL;

    if (type == UNDEFINED || name == NULL)
        return NULL;
    new_col_desc = malloc(sizeof(dataframe_col_desc_t));
    if (new_col_desc == NULL)
        return NULL;
    new_col_desc->column_id = -1;
    new_col_desc->column_name = name;
    new_col_desc->type = type;
    new_col_desc->next = NULL;
    return new_col_desc;
}
