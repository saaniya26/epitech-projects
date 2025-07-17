/*
** EPITECH PROJECT, 2025
** df_types
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_types.h"
#include "dataframe.h"

const dataframe_types_t df_types[] = {
    {BOOL, df_bool_create, df_bool_convert, df_bool_id, df_bool_write,
        df_bool_string},
    {INT, df_int_create, df_int_convert, df_int_id, df_int_write,
        df_int_string},
    {UINT, df_uint_create, df_uint_convert, df_uint_id, df_uint_write,
        df_uint_string},
    {FLOAT, df_float_create, df_float_convert, df_float_id, df_float_write,
        df_float_string},
    {STRING, df_string_create, df_string_convert, df_string_id,
        df_string_write, df_string_string},
    {UNDEFINED, NULL, NULL, NULL, NULL, NULL}
};
