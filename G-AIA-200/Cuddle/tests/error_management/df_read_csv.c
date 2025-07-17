/*
** EPITECH PROJECT, 2025
** df_read_csv
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_read_from_csv, empty)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_empty.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_read_from_csv, invalid_int)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_invalint.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_read_from_csv, no_data_past_header)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_noposthcontent.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_read_from_csv, not_enough_header_cols)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_notenoughhcols.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}

Test(err_mgmt_read_from_csv, too_many_header_cols)
{
    dataframe_t *df = df_read_csv("tests/example_files/incorrect_toomuchhcols.csv", NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}
