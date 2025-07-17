/*
** EPITECH PROJECT, 2025
** G-AIA-200
** File description:
** df_shape
*/

#include "unistd.h"
#include "dataframe.h"
#include "utils.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_shape_t shape;

    shape.nb_rows = 0;
    shape.nb_columns = 0;
    if (dataframe == NULL)
        return shape;
    shape.nb_rows = dataframe->nb_rows;
    shape.nb_columns = dataframe->nb_columns;
    return shape;
}
