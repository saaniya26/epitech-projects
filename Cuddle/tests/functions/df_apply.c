/*
** EPITECH PROJECT, 2025
** df_apply
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "my.h"
#include "dataframe.h"
#include "df_core/df_line.h"

static void *apply_func(void *value)
{
    int *new_value = malloc(sizeof(int));

    *new_value = *(int *) value * 2;
    return new_value;
}

Test(test_df_apply, exists_and_runs)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_apply(df, "age", apply_func);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(*(int *) df_line_get(df2->lines, 2)->cols->next->value, 70,
        "Dataframe didn't properly load data. (Expected %d)", 70);
    df_free(df);
    df_free(df2);
}

Test(test_df_apply, exists_and_runs_custsep)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(my_strcmp((const char *) df->lines->cols->value, "Alice"),
        CMP_EXACT, "Dataframe didn't properly load data. (Expected %s)", "Alice");
    df2 = df_apply(df, "age", apply_func);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(*(int *) df_line_get(df2->lines, 2)->cols->next->value, 70,
        "Dataframe didn't properly load data. (Expected %d)", 70);
    df_free(df);
    df_free(df2);
}
