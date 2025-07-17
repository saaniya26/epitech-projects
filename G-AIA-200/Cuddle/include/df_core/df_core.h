/*
** EPITECH PROJECT, 2025
** df_core
** File description:
** Cuddle
*/

#include <stdio.h>
#include "../utils.h"

#ifndef DF_CORE_H
    #define DF_CORE_H

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    column_type_t type;
    void *(*create_f)(const void *);
    void *(*convert_f)(const char *);
    bool_t (*id_f)(const char *);
    int (*write_f)(void *value, FILE *file);
    char *(*string_f)(const void *value);
} dataframe_types_t;

typedef struct {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;

typedef struct dataframe_col_desc_s {
    int column_id;
    char *column_name;
    column_type_t type;
    struct dataframe_col_desc_s *next;
} dataframe_col_desc_t;

typedef struct dataframe_column_s {
    void *value;
    int col_id;
    dataframe_col_desc_t *col_descriptor;
    struct dataframe_column_s *next;
} dataframe_column_t;

typedef struct dataframe_line_s {
    int n;
    dataframe_column_t *cols;
    struct dataframe_s *dt;
    struct dataframe_line_s *next;
    struct dataframe_line_s *prev;
} dataframe_line_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **initial_header;
    char *separator;
    dataframe_col_desc_t *cols_types;
    dataframe_line_t *lines;
} dataframe_t;

typedef struct df_statistics_s {
    int count;
    float sum;
    float square_sum;
    float min;
    float max;
} df_statistics_t;

dataframe_t *df_create(void);
dataframe_t *df_dup(dataframe_t *src);
void *df_free_n(dataframe_t *dataframe);

#endif
