/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_define
*/

#include <stdlib.h>
#include "df_core/df_core.h"
#include "dataframe.h"
#include "my.h"
#include "my_printf.h"
#include <math.h>

float get_column_value(dataframe_column_t *col, column_type_t type)
{
    if (type == INT)
        return (float)*(int *)col->value;
    if (type == FLOAT)
        return (float)*(float *)col->value;
    if (type == UINT)
        return (float)*(unsigned int *)col->value;
    return 0.0f;
}

void calculations(dataframe_column_t *col, dataframe_col_desc_t *col_desc,
    df_statistics_t *stat)
{
    float val;

    while (col) {
        if (col->col_id != col_desc->column_id || col->value == NULL) {
            col = col->next;
            continue;
        }
        val = get_column_value(col, col_desc->type);
        stat->sum += val;
        stat->square_sum += val * val;
        stat->min = (val < stat->min) ? val : stat->min;
        stat->max = (val > stat->max) ? val : stat->max;
        stat->count++;
        col = col->next;
    }
}

void calculate_stats(dataframe_t *df, dataframe_col_desc_t *col_desc,
    df_statistics_t *stat)
{
    dataframe_line_t *line = df->lines;
    dataframe_column_t *col;

    while (line) {
        col = line->cols;
        calculations(col, col_desc, stat);
        line = line->next;
    }
}

void print_stats(const char *column_name, df_statistics_t *stat)
{
    float mean = 0.0f;
    float variance = 0.0f;
    float stddev = 0.0f;

    if (stat->count > 1) {
        mean = stat->sum / stat->count;
        variance = (stat->square_sum / stat->count) - (mean * mean);
        variance = variance < 0 ? 0 : variance;
        stddev = sqrt(variance);
    }
    printf("Column: %s\n", column_name);
    printf("Count: %d\n", stat->count);
    printf("Mean: %.2f\n", mean);
    printf("Std: %.2f\n", stddev);
    printf("Min: %.2f\n", stat->min);
    printf("Max: %.2f\n", stat->max);
    fflush(stdout);
}

void df_describe(dataframe_t *df)
{
    dataframe_col_desc_t *col_desc;
    df_statistics_t stat;

    if (df == NULL || df->cols_types == NULL || df->lines == NULL)
        return;
    col_desc = df->cols_types;
    while (col_desc) {
        if (col_desc->type == INT || col_desc->type == UINT
            || col_desc->type == FLOAT) {
            stat.count = 0;
            stat.sum = 0;
            stat.square_sum = 0;
            stat.min = __DBL_MAX__;
            stat.max = -__DBL_MAX__;
            calculate_stats(df, col_desc, &stat);
            print_stats(col_desc->column_name, &stat);
        }
        col_desc = col_desc->next;
    }
}
