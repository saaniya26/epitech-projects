/*
** EPITECH PROJECT, 2025
** df_dup
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "my.h"
#include "dataframe.h"

Test(test_df_dup, exists_and_runs_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df2 = df_dup(df);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(df2->cols_types != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->cols_types);
    cr_assert_eq(df2->initial_header != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->initial_header);
    cr_assert_eq(df2->lines != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->lines);
    cr_assert_eq(df2->nb_columns == df->nb_columns, TRUE,
        "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_columns);
    cr_assert_eq(df2->nb_rows == df->nb_rows, TRUE, "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_rows);
    cr_assert_eq(my_strcmp(df->separator, df2->separator), CMP_EXACT,
        "Dataframe dup hasn't returned same separator");
    df_free(df);
    df_free(df2);
}

Test(test_df_dup, exists_and_runs_custsep_1)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df2 = df_dup(df);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(df2->cols_types != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->cols_types);
    cr_assert_eq(df2->initial_header != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->initial_header);
    cr_assert_eq(df2->lines != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->lines);
    cr_assert_eq(df2->nb_columns == df->nb_columns, TRUE,
        "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_columns);
    cr_assert_eq(df2->nb_rows == df->nb_rows, TRUE, "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_rows);
    cr_assert_eq(my_strcmp(df->separator, df2->separator), CMP_EXACT,
        "Dataframe dup hasn't returned same separator");
    df_free(df);
    df_free(df2);
}

Test(test_df_dup, exists_and_runs_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2.csv", NULL);
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df2 = df_dup(df);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(df2->cols_types != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->cols_types);
    cr_assert_eq(df2->initial_header != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->initial_header);
    cr_assert_eq(df2->lines != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->lines);
    cr_assert_eq(df2->nb_columns == df->nb_columns, TRUE,
        "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_columns);
    cr_assert_eq(df2->nb_rows == df->nb_rows, TRUE, "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_rows);
    cr_assert_eq(my_strcmp(df->separator, df2->separator), CMP_EXACT,
        "Dataframe dup hasn't returned same separator");
    df_free(df);
    df_free(df2);
}

Test(test_df_dup, exists_and_runs_custsep_2)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct2-bis.csv", ";");
    dataframe_t *df2 = NULL;

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df2 = df_dup(df);
    cr_assert_eq(df2 != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2);
    cr_assert_eq(df2->cols_types != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->cols_types);
    cr_assert_eq(df2->initial_header != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->initial_header);
    cr_assert_eq(df2->lines != NULL, TRUE, "Dataframe dup hasn't returned proper pointer (Got %p)", df2->lines);
    cr_assert_eq(df2->nb_columns == df->nb_columns, TRUE,
        "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_columns);
    cr_assert_eq(df2->nb_rows == df->nb_rows, TRUE, "Dataframe dup hasn't returned proper int (Got %d)", df2->nb_rows);
    cr_assert_eq(my_strcmp(df->separator, df2->separator), CMP_EXACT,
        "Dataframe dup hasn't returned same separator");
    df_free(df);
    df_free(df2);
}
