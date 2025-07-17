/*
** EPITECH PROJECT, 2025
** df_free
** File description:
** Cuddle (Test)
*/

#include <criterion/criterion.h>
#include "dataframe.h"
#include "my.h"

Test(test_df_free, exists_and_runs)
{
    dataframe_t *df = df_read_csv("tests/example_files/correct1.csv", NULL);

    cr_assert_eq(df != NULL, TRUE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}
