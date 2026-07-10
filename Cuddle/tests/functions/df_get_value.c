/*
** EPITECH PROJECT, 2025
** df_get_value
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include "dataframe.h"
#include "df_core/df_line.h"
#include "my.h"

Test(test_df_get_value, exists_and_runs_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    cr_assert_eq(*(int *) df_get_value(df, 0, "age"), 25,
        "Dataframe didn't properly load data. (Expected %d)", 25);
    df_free(df);
}

Test(test_df_get_value, exists_and_runs_custsep_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    cr_assert_eq(*(int *) df_get_value(df, 0, "age"), 25,
        "Dataframe didn't properly load data. (Expected %d)", 25);
    df_free(df);
}

Test(test_df_get_value, exists_and_runs_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    cr_assert_eq(*(int *) df_get_value(df, 5, "age"), 35,
        "Dataframe didn't properly load data. (Expected %d)", 30);
    df_free(df);
}

Test(test_df_get_value, exists_and_runs_custsep_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    cr_assert_eq(*(int *) df_get_value(df, 5, "age"), 35,
        "Dataframe didn't properly load data. (Expected %d)", 30);
    df_free(df);
}
