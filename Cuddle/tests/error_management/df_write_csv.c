/*
** EPITECH PROJECT, 2025
** df_write_csv
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_write_csv, empty)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_empty.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/incorrect_empty-out.csv"), FUNC_FAILED,
        "Function hasn't returned proper exit code (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_write_csv, invalid_int)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_invalint.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/incorrect_invalint-out.csv"), FUNC_FAILED,
        "Function hasn't returned proper exit code (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_write_csv, no_data_past_header)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_noposthcontent.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/incorrect_noposthcontent-out.csv"), FUNC_FAILED,
        "Function hasn't returned proper exit code (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_write_csv, not_enough_header_cols)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_notenoughhcols.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/incorrect_notenoughhcols-out.csv"), FUNC_FAILED,
        "Function hasn't returned proper exit code (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_write_csv, too_many_header_cols)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_toomuchhcols.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(df_write_csv(df, "tests/example_files/incorrect_toomuchhcols-out.csv"), FUNC_FAILED,
        "Function hasn't returned proper exit code (Got %p)", df);
    df_free(df);
}
