/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_groupby
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "dataframe.h"
#include "df_core/df_line.h"
#include "df_core/df_col.h"

dataframe_t *df_groupby(dataframe_t *dataframe, const char
    *aggregate_by, const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values)
)
{
    if (dataframe == NULL || aggregate_by == NULL ||
        to_aggregate == NULL || agg_func == NULL)
        return NULL;
    return NULL;
}
