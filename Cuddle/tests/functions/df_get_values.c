/*
** EPITECH PROJECT, 2025
** df_get_values
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include "dataframe.h"
#include "df_core/df_line.h"
#include "my.h"

Test(test_df_get_values, exists_and_runs_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    void **data = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    data = df_get_values(df, "age");
    cr_assert_eq(data != NULL, TRUE, "Output data hasn't returned proper pointer (Got %p)", data);
    cr_assert_eq(*(int *) data[0], 25,
        "Dataframe didn't properly load data. (Expected %d)", 25);
    free(data);
    df_free(df);
}

Test(test_df_get_values, exists_and_runs_custsep_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    void **data = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    data = df_get_values(df, "age");
    cr_assert_eq(data != NULL, TRUE, "Output data hasn't returned proper pointer (Got %p)", data);
    cr_assert_eq(*(int *) data[0], 25,
        "Dataframe didn't properly load data. (Expected %d)", 25);
    free(data);
    df_free(df);
}

Test(test_df_get_values, exists_and_runs_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    void **data = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    data = df_get_values(df, "age");
    cr_assert_eq(data != NULL, TRUE, "Output data hasn't returned proper pointer (Got %p)", data);
    cr_assert_eq(*(int *) data[5], 35,
        "Dataframe didn't properly load data. (Expected %d)", 35);
    free(data);
    df_free(df);
}

Test(test_df_get_values, exists_and_runs_custsep_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    void **data = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    data = df_get_values(df, "age");
    cr_assert_eq(data != NULL, TRUE, "Output data hasn't returned proper pointer (Got %p)", data);
    cr_assert_eq(*(int *) data[5], 35,
        "Dataframe didn't properly load data. (Expected %d)", 35);
    free(data);
    df_free(df);
}
