/*
** EPITECH PROJECT, 2025
** dataframe
** File description:
** Cuddle
*/

#include <stdint.h>
#include <stdbool.h>
#include "df_core/df_core.h"
#include "utils.h"

#ifndef DF_DATAFRAME_CORE_H
    #define DF_DATAFRAME_CORE_H

    #define DEFAULT_SEPARATOR ","
    #define SEPARATOR(sep)  (sep != NULL ? sep : DEFAULT_SEPARATOR)

dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);

#endif

#ifndef DF_DATAFRAME_BASIC_H
    #define DF_DATAFRAME_BASIC_H

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
void df_describe(dataframe_t *dataframe);

#endif

#ifndef DF_DATAFRAME_ADV_H
    #define DF_DATAFRAME_ADV_H
dataframe_t *df_filter(dataframe_t *dataframe, const char *column,
    bool (*filter_func)(void *value));
dataframe_t *df_sort(dataframe_t *dataframe, const char *column,
    bool (*sort_func)(void *value1, void *value2));
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *dataframe, const char *column,
    column_type_t downcast);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);
dataframe_t *df_groupby(dataframe_t *dataframe, const char
    *aggregate_by, const char **to_aggregate,
    void *(*agg_func)(void **values, int nb_values)
);

#endif
