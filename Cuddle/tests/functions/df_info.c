/*
** EPITECH PROJECT, 2025
** df_info
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "my.h"

Test(test_df_info, exists_and_runs, .init = cr_redirect_stdout)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_info(df);
    cr_assert_stdout_eq_str(
        "3 columns:\n"\
        "- name: string\n"\
        "- age: unsigned int\n"\
        "- city: string\n", ""
    );
    df_free(df);
}
