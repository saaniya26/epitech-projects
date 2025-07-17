/*
** EPITECH PROJECT, 2025
** df_write_csv
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "dataframe.h"

Test(test_df_write_csv, exists_and_runs_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/correct1-out.csv"), FUNC_SUCCESS,
        "CSV Write has returned failed status code");
    df_free(df);
}

Test(test_df_write_csv, exists_and_runs_custsep_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/correct1-bis-out.csv"), FUNC_SUCCESS,
        "CSV Write has returned failed status code");
    df_free(df);
}

Test(test_df_write_csv, exists_and_runs_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/correct2-out.csv"), FUNC_SUCCESS,
        "CSV Write has returned failed status code");
    df_free(df);
}

Test(test_df_write_csv, exists_and_runs_custsep_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2-bis.csv", ";");

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/correct2-bis-out.csv"), FUNC_SUCCESS,
        "CSV Write has returned failed status code");
    df_free(df);
}
