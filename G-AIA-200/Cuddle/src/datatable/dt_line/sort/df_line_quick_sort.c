/*
** EPITECH PROJECT, 2024
** df_line_quick_sort
** File description:
** Organized
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "df_core/df_col.h"
#include "df_core/df_line.h"
#include "my.h"
#include "utils.h"

static void df_quick_sort_swap(dataframe_line_t *line_1,
    dataframe_line_t *line_2)
{
    dataframe_line_t swap = {-1, NULL, NULL, NULL, NULL};

    if (line_1 == NULL || line_2 == NULL)
        return;
    swap.n = line_1->n;
    swap.dt = line_1->dt;
    swap.cols = line_1->cols;
    line_1->n = line_2->n;
    line_1->dt = line_2->dt;
    line_1->cols = line_2->cols;
    line_2->n = swap.n;
    line_2->dt = swap.dt;
    line_2->cols = swap.cols;
}

static void *get_line_value(dataframe_line_t *line, const char *column)
{
    dataframe_column_t *col = NULL;

    if (line == NULL || column == NULL)
        return NULL;
    col = df_col_get_name(line->cols, column);
    if (col == NULL)
        return NULL;
    return col->value;
}

static dataframe_line_t *df_quick_sort_part(dataframe_line_t *start,
    dataframe_line_t *end, bool (*df_cmp)(void *, void *),
    const char *column
)
{
    dataframe_line_t *pivot = start;
    dataframe_line_t *prev_hard = start;
    dataframe_line_t *curr_hard = start;

    if (start == NULL || end == NULL || df_cmp == NULL || column == NULL)
        return NULL;
    while (curr_hard != end->next) {
        if (df_cmp(get_line_value(pivot, column),
            get_line_value(curr_hard, column)) == true) {
            df_quick_sort_swap(curr_hard, prev_hard->next);
            prev_hard = prev_hard->next;
        }
        curr_hard = curr_hard->next;
    }
    df_quick_sort_swap(pivot, prev_hard);
    return prev_hard;
}

static void df_quick_sort_rec(dataframe_line_t *start, dataframe_line_t *end,
    bool (*df_cmp)(void *, void *),
    const char *column
)
{
    dataframe_line_t *pivot = df_quick_sort_part(start, end, df_cmp, column);

    if (start == NULL || end == NULL || df_cmp == NULL || column == NULL)
        return;
    if (start == end)
        return;
    df_quick_sort_rec(start, pivot, df_cmp, column);
    df_quick_sort_rec(pivot->next, end, df_cmp, column);
}

static bool check_column(dataframe_t *df, const char *column)
{
    dataframe_line_t *line = NULL;
    dataframe_column_t *col = NULL;

    if (df == NULL || column == NULL)
        return FALSE;
    line = df->lines;
    if (line == NULL)
        return FALSE;
    col = df_col_get_name(line->cols, column);
    if (col == NULL)
        return FALSE;
    return TRUE;
}

int df_line_quick_sort(dataframe_t *df, bool (*df_cmp)(void *, void *),
    const char *column)
{
    if (df == NULL || df_cmp == NULL || column == NULL)
        return FUNC_FAILED;
    if (check_column(df, column) == FALSE)
        return FUNC_FAILED;
    df_quick_sort_rec(df_line_get(df->lines, 0),
        df_line_get(df->lines, -1), df_cmp, column);
    return FUNC_SUCCESS;
}
