/*
** EPITECH PROJECT, 2025
** df_col
** File description:
** Cuddle
*/

#include "df_core.h"

#ifndef DF_COL_H
    #define DF_COL_H

int df_col_chain(dataframe_column_t **chain, dataframe_column_t *new_chain);
dataframe_column_t *df_col_create(dataframe_col_desc_t *descriptor,
    void *value);
dataframe_column_t *df_col_dup(dataframe_col_desc_t *desc,
    dataframe_column_t *src);
dataframe_column_t *df_col_dup_chain(dataframe_col_desc_t *desc,
    dataframe_column_t *src);
dataframe_column_t *df_col_get(dataframe_column_t *cols,
    int index);
int df_col_verify(dataframe_t *dt, char **args);
void df_col_free(dataframe_column_t *col);
dataframe_column_t *df_col_get_name(dataframe_column_t *cols,
    const char *name);

dataframe_col_desc_t *df_col_desc_create(column_type_t type, char *name);
int df_col_desc_chain(dataframe_col_desc_t **chain,
    dataframe_col_desc_t *new_chain);
column_type_t df_col_desc_get_type(dataframe_col_desc_t *cols_desc,
    int index);
dataframe_col_desc_t *df_col_desc_get(dataframe_col_desc_t *cols_desc,
    int index);
dataframe_col_desc_t *df_col_desc_get_name(dataframe_col_desc_t *cols_desc,
    const char *column);
column_type_t df_col_desc_get_name_type(dataframe_col_desc_t *cols_desc,
    const char *column);
dataframe_col_desc_t *df_col_desc_dup(dataframe_col_desc_t *src);
void df_col_desc_destroy(dataframe_col_desc_t *col_desc);
int df_col_promote(dataframe_t *dt, column_type_t type, const char *column);
int df_col_desc_check(dataframe_t *dt, const char *column, bool_t patch);
int df_col_desc_check_global(dataframe_t *dt, bool_t patch);

    #define COL_DESC(col)   (col->col_descriptor)
    #define COL_T_DIR(col)   (COL_DESC(col)->type)
    #define COL_T(col)   (COL_DESC(col) != NULL ? COL_T_DIR(col) : UNDEFINED)

#endif
