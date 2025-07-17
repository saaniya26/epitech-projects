/*
** EPITECH PROJECT, 2025
** df_get_value
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_get_value, null)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    void *value = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    value = df_get_value(NULL, -1, NULL);
    cr_assert_eq(value != NULL, FALSE, "Value hasn't returned proper pointer (Got %p)", value);
    df_free(df);
}

Test(err_mgmt_get_value, out_of_range_rows)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    void *value = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    value = df_get_value(df, 90, "age");
    cr_assert_eq(value != NULL, FALSE, "Value hasn't returned proper pointer (Got %p)", value);
    df_free(df);
}

Test(err_mgmt_get_value, unknown_column)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    void *value = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    value = df_get_value(df, 3, "agel");
    cr_assert_eq(value != NULL, FALSE, "Value hasn't returned proper pointer (Got %p)", value);
    df_free(df);
}
