/*
** EPITECH PROJECT, 2025
** df_col_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

dataframe_column_t *df_col_create(dataframe_col_desc_t *descriptor,
    void *value)
{
    dataframe_column_t *new_col = malloc(sizeof(dataframe_column_t));

    if (new_col == NULL)
        return NULL;
    new_col->col_id = -1;
    new_col->col_descriptor = descriptor;
    new_col->value = value;
    new_col->next = NULL;
    return new_col;
}
