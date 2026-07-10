/*
** EPITECH PROJECT, 2025
** df_col_chain
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "utils.h"

int df_col_chain(dataframe_column_t **chain, dataframe_column_t *new_chain)
{
    int id = 0;
    dataframe_column_t *curr_chain = NULL;

    if (chain == NULL || new_chain == NULL)
        return FUNC_FAILED;
    if (*chain == NULL) {
        *chain = new_chain;
        return FUNC_SUCCESS;
    }
    for (curr_chain = *chain; curr_chain->next != NULL;
        curr_chain = curr_chain->next)
        id++;
    curr_chain->col_id = id;
    curr_chain->next = new_chain;
    return FUNC_SUCCESS;
}
