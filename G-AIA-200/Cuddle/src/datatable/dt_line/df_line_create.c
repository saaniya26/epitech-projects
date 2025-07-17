/*
** EPITECH PROJECT, 2025
** df_line_create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

dataframe_line_t *df_line_create(dataframe_t *dt)
{
    dataframe_line_t *new_line = NULL;

    if (dt == NULL)
        return NULL;
    new_line = malloc(sizeof(dataframe_line_t));
    if (new_line == NULL)
        return NULL;
    new_line->n = -1;
    new_line->cols = NULL;
    new_line->dt = dt;
    new_line->next = NULL;
    new_line->prev = NULL;
    return new_line;
}
