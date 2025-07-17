/*
** EPITECH PROJECT, 2025
** df_read_csv
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "my.h"
#include "dataframe.h"

Test(test_df_read_csv, exists_and_runs_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df_free(df);
}

Test(test_df_read_csv, exists_and_runs_custsep_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df_free(df);
}

Test(test_df_read_csv, exists_and_runs_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df_free(df);
}

Test(test_df_read_csv, exists_and_runs_custsep_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df_free(df);
}
