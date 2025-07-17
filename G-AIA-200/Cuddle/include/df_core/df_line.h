/*
** EPITECH PROJECT, 2025
** df_line
** File description:
** Cuddle
*/

#include <stdbool.h>
#include "df_core.h"

#ifndef DF_LINE_H
    #define DF_LINE_H

dataframe_line_t *df_line_create(dataframe_t *dt);
int df_line_chain(dataframe_line_t **chain, dataframe_line_t *new_chain);
int df_line_copy_ctl(dataframe_line_t *line, char **cols);
dataframe_line_t *df_line_dup(dataframe_t *dt, dataframe_line_t *src);
int df_line_len(dataframe_line_t *line);
void df_line_free(dataframe_line_t *line);
void df_line_destroy(dataframe_line_t *line);
void df_line_destroy_rev(dataframe_line_t *line);
dataframe_line_t *df_line_get(dataframe_line_t *line, int i);
int df_line_delete(dataframe_line_t *line);
int df_line_quick_sort(dataframe_t *df, bool (*df_cmp)(void *, void *),
    const char *column);

#endif
