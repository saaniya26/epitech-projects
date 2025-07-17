/*
** EPITECH PROJECT, 2025
** df_types
** File description:
** Cuddle
*/

#include "df_core.h"
#include "types/df_bool.h"
#include "types/df_float.h"
#include "types/df_int.h"
#include "types/df_string.h"
#include "types/df_uint.h"

#ifndef DF_TYPES_H
    #define DF_TYPES_H

void *df_create_value(const void *value, column_type_t type);
void *df_convert_value(const char *string, column_type_t type);
dataframe_col_desc_t *df_get_types(dataframe_t *dt, const char **data);
column_type_t df_id_value(const char *string);
int df_write_value(dataframe_column_t *col, FILE *file);
char *df_get_valstring(const void *value, column_type_t type);
bool_t df_can_be_type(const void *value, column_type_t original_type,
    column_type_t target_type);

extern const dataframe_types_t df_types[];

#endif
