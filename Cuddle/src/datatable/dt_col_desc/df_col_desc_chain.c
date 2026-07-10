/*
** EPITECH PROJECT, 2025
** df_col_desc_chain
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

int df_col_desc_chain(dataframe_col_desc_t **chain,
    dataframe_col_desc_t *new_chain)
{
    int id = 1;
    dataframe_col_desc_t *curr_chain = NULL;

    if (chain == NULL || new_chain == NULL)
        return FUNC_FAILED;
    if (*chain == NULL) {
        new_chain->column_id = 0;
        *chain = new_chain;
        return FUNC_SUCCESS;
    }
    for (curr_chain = *chain; curr_chain->next != NULL;
        curr_chain = curr_chain->next)
        id++;
    new_chain->column_id = id;
    curr_chain->next = new_chain;
    return FUNC_SUCCESS;
}
