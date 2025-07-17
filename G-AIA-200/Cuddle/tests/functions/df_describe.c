/*
** EPITECH PROJECT, 2025
** df_describe
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "my.h"

Test(test_df_describe, exists_and_runs, .init = cr_redirect_stdout)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_describe(df);
    cr_assert_stdout_eq_str(
        "Column: age\n"\
        "Count: 7\n"\
        "Mean: 29.29\n"\
        "Std: 4.16\n"\
        "Min: 25.00\n"\
        "Max: 35.00\n", ""
    );
    df_free(df);
}
