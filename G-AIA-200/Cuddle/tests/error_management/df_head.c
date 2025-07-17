/*
** EPITECH PROJECT, 2025
** df_head
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_head, null)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_head(NULL, 3);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}

Test(test_df_head, incorrect_row)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_head(df, 0);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df2 = df_head(df, -1);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}
