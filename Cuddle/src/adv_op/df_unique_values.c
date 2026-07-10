/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_unique_values
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "dataframe.h"
#include "df_core/df_line.h"
#include "df_core/df_col.h"

static void fill_array(int count, void **unique, void **temp)
{
    for (int i = 0; i < count; i++)
        unique[i] = temp[i];
}

static int check_list(void **values, int count, void *value)
{
    for (int i = 0; i < count; i++) {
        if (my_strcmp((char *)values[i], (char *)value) == 0)
            return 1;
        if ((int *)values[i] == (int *)value)
            return 1;
    }
    return 0;
}

void **df_get_unique_values(dataframe_t *dataframe, const char *column)
{
    if (dataframe == NULL || column == NULL)
        return NULL;
    return NULL;
}

void **df_get_unique_values_legacy(dataframe_t *dataframe, const char *column)
{
    void **unique_values;
    void **temp_values;
    dataframe_line_t *line;
    dataframe_column_t *col;
    int count = 0;

    if (dataframe == NULL || column == NULL || dataframe->nb_rows <= 0)
        return NULL;
    temp_values = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    for (line = dataframe->lines; line != NULL; line = line->next) {
        col = df_col_get_name(line->cols, column);
        if (check_list(temp_values, count, col->value) == 0) {
            temp_values[count] = col->value;
            count++;
        }
    }
    unique_values = malloc(sizeof(void *) * (count + 1));
    fill_array(count, unique_values, temp_values);
    unique_values[count] = NULL;
    return unique_values;
}
