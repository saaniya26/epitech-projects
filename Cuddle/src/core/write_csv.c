/*
** EPITECH PROJECT, 2025
** read_from_csv
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "df_core/df_core.h"
#include "df_core/df_line.h"
#include "df_core/df_types.h"
#include "dataframe.h"
#include "getline.h"
#include "utils.h"

static int write_delim(dataframe_t *dt, FILE *file)
{
    if (dt == NULL || file == NULL)
        return FUNC_FAILED;
    fwrite(dt->separator, sizeof(char), my_strlen(dt->separator),
        file);
    return FUNC_SUCCESS;
}

static int write_header(dataframe_t *dt, FILE *file)
{
    dataframe_col_desc_t *desc = NULL;

    if (dt == NULL || file == NULL)
        return FUNC_FAILED;
    if (dt->cols_types == NULL)
        return FUNC_FAILED;
    for (desc = dt->cols_types; desc != NULL; desc = desc->next) {
        fwrite(desc->column_name, sizeof(char), my_strlen(desc->column_name),
            file);
        if (desc->next != NULL)
            write_delim(dt, file);
    }
    fwrite("\n", sizeof(char), 1, file);
    return FUNC_SUCCESS;
}

static int write_column(dataframe_t *dt, dataframe_column_t *col,
    FILE *file)
{
    int ret_stat = FUNC_SUCCESS;

    if (col == NULL || file == NULL)
        return FUNC_FAILED;
    for (; col != NULL && ret_stat == FUNC_SUCCESS; col = col->next) {
        ret_stat = df_write_value(col, file);
        if (col->next != NULL)
            write_delim(dt, file);
    }
    return ret_stat;
}

static int write_file(dataframe_t *dt, FILE *file)
{
    int ret_stat = FUNC_SUCCESS;
    dataframe_line_t *line = NULL;

    if (dt == NULL || file == NULL)
        return FUNC_FAILED;
    if (dt->lines == NULL)
        return FUNC_FAILED;
    for (line = dt->lines; line != NULL && ret_stat == FUNC_SUCCESS;
        line = line->next) {
        ret_stat = write_column(dt, line->cols, file);
        fwrite("\n", sizeof(char), 1, file);
    }
    return ret_stat;
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    FILE *file = NULL;

    if (dataframe == NULL || filename == NULL)
        return FUNC_FAILED;
    file = fopen(filename, "w");
    if (file == NULL)
        return FUNC_FAILED;
    if (write_header(dataframe, file) == FUNC_FAILED) {
        fclose(file);
        return FUNC_FAILED;
    }
    if (write_file(dataframe, file) == FUNC_FAILED) {
        fclose(file);
        return FUNC_FAILED;
    }
    fclose(file);
    return FUNC_SUCCESS;
}
