/*
** EPITECH PROJECT, 2025
** df_filter
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

static bool filter_func_1(void *value)
{
    return *(int *) value > 30;
}

Test(err_mgmt_filter, null)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(NULL, NULL, NULL);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}

Test(err_mgmt_filter, incorrect_row)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_filter(df, "ages", filter_func_1);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}
