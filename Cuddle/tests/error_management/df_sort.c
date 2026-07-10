/*
** EPITECH PROJECT, 2025
** df_sort
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "dataframe.h"
#include "utils.h"

static bool sort_func(void *value1, void *value2)
{
    return *(int *) value1 > *(int *) value2;
}

Test(err_mgmt_sort, null)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_sort(NULL, NULL, NULL);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}

Test(err_mgmt_sort, incorrect_row)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_sort(df, "ages", sort_func);
    cr_assert_eq(df2 != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
    df_free(df2);
}
