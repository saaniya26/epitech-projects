/*
** EPITECH PROJECT, 2025
** read_from_csv
** File description:
** Cuddle
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "fs_utils.h"
#include "df_core/df_core.h"
#include "df_core/df_line.h"
#include "df_core/df_col.h"
#include "df_core/df_types.h"
#include "dataframe.h"
#include "getline.h"
#include "utils.h"

static int get_type(dataframe_t *dt, FILE *file, char *full_seps)
{
    long curr_pos = 0;
    char *temp_buff = NULL;
    char **temp_tab = NULL;

    if (dt == NULL || file == NULL)
        return FUNC_FAILED;
    curr_pos = ftell(file);
    if (getline(&temp_buff, &(size_t) {0}, file) == FUNC_FAILED) {
        free(temp_buff);
        return FUNC_FAILED;
    }
    temp_tab = my_sepstr(temp_buff, full_seps);
    free(temp_buff);
    dt->cols_types = df_get_types(dt, (const char **) temp_tab);
    my_tabfree((void **) temp_tab);
    fseek(file, curr_pos, SEEK_SET);
    return FUNC_SUCCESS;
}

static int read_header(dataframe_t *dt, FILE *file, const char *sep)
{
    size_t size = 0;
    char *buffer = NULL;
    char *full_seps = NULL;

    if (dt == NULL || file == NULL || sep == NULL)
        return FUNC_FAILED;
    if (getline(&buffer, &size, file) == FUNC_FAILED || size == 0) {
        free(buffer);
        return FUNC_FAILED;
    }
    full_seps = my_strcdup(sep, "\n");
    dt->separator = my_strdup(sep);
    dt->initial_header = my_sepstr(buffer, full_seps);
    dt->nb_columns = my_tablen((const void **) dt->initial_header);
    get_type(dt, file, full_seps);
    my_vfree(2, buffer, full_seps);
    return (dt->initial_header == NULL || dt->nb_columns <= 0) ? FUNC_FAILED
        : FUNC_SUCCESS;
}

static dataframe_line_t *make_line(dataframe_t *dt, char **buffer)
{
    dataframe_line_t *line = NULL;

    if (buffer == NULL) {
        my_tabfree((void **) buffer);
        return NULL;
    }
    line = df_line_create(dt);
    if (line == NULL) {
        my_tabfree((void **) buffer);
        return NULL;
    }
    if (df_line_copy_ctl(line, buffer) == FUNC_FAILED) {
        free(line);
        my_tabfree((void **) buffer);
        return NULL;
    }
    my_tabfree((void **) buffer);
    return line;
}

static int process_column(dataframe_t *dt, FILE *file,
    const char *full_seps)
{
    char *buffer = NULL;

    if (dt == NULL || file == NULL || full_seps == NULL)
        return FUNC_FAILED;
    if (getline(&buffer, &(size_t) {0}, file) == FUNC_FAILED) {
        free(buffer);
        return FUNC_SEMFAIL;
    }
    if (my_strcmp(buffer, "") == CMP_EXACT) {
        free(buffer);
        return FUNC_SEMFAIL;
    }
    if (df_line_chain(&dt->lines, make_line(dt,
        my_sepstr(buffer, full_seps))) == FUNC_FAILED) {
        free(buffer);
        return FUNC_FAILED;
    }
    free(buffer);
    return FUNC_SUCCESS;
}

static int read_file(dataframe_t *dt, FILE *file, const char *sep)
{
    char *full_seps = my_strcdup(sep, "\n");
    int ret_stat = FUNC_SUCCESS;

    if (dt == NULL || file == NULL || sep == NULL || full_seps == NULL) {
        free(full_seps);
        return FUNC_FAILED;
    }
    for (int i = 0; ret_stat == FUNC_SUCCESS; i++) {
        ret_stat = process_column(dt, file, full_seps);
        if (ret_stat == FUNC_FAILED) {
            free(full_seps);
            return FUNC_FAILED;
        }
    }
    free(full_seps);
    dt->nb_rows = df_line_len(dt->lines);
    return dt->lines != NULL ? FUNC_SUCCESS : FUNC_FAILED;
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *file = NULL;
    dataframe_t *new_df = NULL;

    if (filename == NULL)
        return NULL;
    new_df = df_create();
    file = fopen(filename, "r");
    if (read_header(new_df, file, SEPARATOR(separator)) == FUNC_FAILED) {
        fs_fclose(file);
        df_free(new_df);
        return NULL;
    }
    if (read_file(new_df, file, SEPARATOR(separator)) == FUNC_FAILED) {
        fs_fclose(file);
        df_free(new_df);
        return NULL;
    }
    fclose(file);
    df_col_desc_check_global(new_df, TRUE);
    return new_df;
}
