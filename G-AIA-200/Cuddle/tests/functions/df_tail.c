/*
** EPITECH PROJECT, 2025
** df_tail
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "my.h"
#include "dataframe.h"
#include "df_core/df_line.h"

Test(test_df_tail, exists_and_runs)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_tail(df, 3);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Nathan"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Nathan");
    df_free(df);
    df_free(df2);
}

Test(test_df_tail, exists_and_runs_custsep)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_tail(df, 3);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Nathan"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Nathan");
    df_free(df);
    df_free(df2);
}

Test(test_df_tail, overruns_len)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_tail(df, 3);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df2->lines->cols->value, "Nathan"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Nathan");
    df_free(df);
    df_free(df2);
}
