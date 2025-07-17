/*
** EPITECH PROJECT, 2025
** df_get_value
** File description:
** Cuddle
*/

#include <stdlib.h>
#include <stdbool.h>
#include "dataframe.h"
#include "df_core/df_line.h"
#include "df_core/df_col.h"

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    void **data = NULL;

    if (dataframe == NULL || column == NULL)
        return NULL;
    if (dataframe->nb_rows <= 0)
        return NULL;
    data = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (data == NULL)
        return NULL;
    data[dataframe->nb_rows] = NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        data[i] = df_get_value(dataframe, i, column);
        if (data[i] == NULL) {
            free(data);
            return NULL;
        }
    }
    return data;
}
