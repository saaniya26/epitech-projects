/*
** EPITECH PROJECT, 2025
** df_filter
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "my.h"
#include "dataframe.h"
#include "df_core/df_line.h"

static bool filter_func_1(void *value)
{
    return *(int *) value > 30;
}

static bool filter_func_err_keepall(void *value)
{
    return *(int *) value > 0;
}

static bool filter_func_err_killall(void *value)
{
    return *(int *) value < 0;
}

Test(test_df_filter, exists_and_runs)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(df, "age", filter_func_1);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Charlie"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Charlie");
    df_free(df);
    df_free(df2);
}

Test(test_df_filter, exists_and_runs_custsep)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(df, "age", filter_func_1);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Charlie"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Charlie");
    df_free(df);
    df_free(df2);
}

Test(test_df_filter, all_elements_preserved)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(df, "age", filter_func_err_keepall);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df_free(df);
    df_free(df2);
}

Test(test_df_filter, all_elements_deleted)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(df, "age", filter_func_err_killall);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(df2->lines == NULL, TRUE,
        "Dataframe lines hasn't returned proper pointer (Got %p)", df2->lines);
    df_free(df);
    df_free(df2);
}
