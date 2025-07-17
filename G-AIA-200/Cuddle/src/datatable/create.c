/*
** EPITECH PROJECT, 2025
** create
** File description:
** Cuddle
*/

#include <stdlib.h>
#include "dataframe.h"
#include "utils.h"

dataframe_t *df_create(void)
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));

    new_df->nb_rows = 0;
    new_df->nb_columns = 0;
    new_df->initial_header = NULL;
    new_df->separator = NULL;
    new_df->cols_types = NULL;
    new_df->lines = NULL;
    return new_df;
}
