/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_info
*/

#include <stdlib.h>
#include "dataframe.h"
#include "df_core/df_col.h"
#include "my.h"
#include "my_printf.h"

void print_type(dataframe_col_desc_t *cols_types)
{
    switch (cols_types->type) {
        case BOOL:
            my_printf("bool\n");
            break;
        case INT:
            my_printf("int\n");
            break;
        case UINT:
            my_printf("unsigned int\n");
            break;
        case FLOAT:
            my_printf("float\n");
            break;
        case STRING:
            my_printf("string\n");
            break;
        default:
            my_printf("undefined\n");
            break;
    }
}

void df_info(dataframe_t *dataframe)
{
    dataframe_col_desc_t *col_desc = NULL;

    if (dataframe == NULL)
        return;
    my_printf("%d columns:\n", dataframe->nb_columns);
    for (int i = 0; i < dataframe->nb_columns; i++) {
        col_desc = df_col_desc_get(dataframe->cols_types, i);
        my_printf("- %s: ", col_desc != NULL ? col_desc->column_name
            : "(UNKN)");
        print_type(col_desc);
    }
}
