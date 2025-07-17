/*
** EPITECH PROJECT, 2025
** df_line_chain
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

int df_line_chain(dataframe_line_t **chain, dataframe_line_t *new_chain)
{
    int n = 2;
    dataframe_line_t *curr_chain = NULL;

    if (chain == NULL || new_chain == NULL)
        return FUNC_FAILED;
    if (*chain == NULL) {
        new_chain->n = 1;
        *chain = new_chain;
        return FUNC_SUCCESS;
    }
    for (curr_chain = *chain; curr_chain->next != NULL;
        curr_chain = curr_chain->next)
        n++;
    new_chain->n = n;
    curr_chain->next = new_chain;
    new_chain->prev = curr_chain;
    return FUNC_SUCCESS;
}
