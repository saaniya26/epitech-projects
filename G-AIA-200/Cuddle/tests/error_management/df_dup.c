/*
** EPITECH PROJECT, 2025
** df_dup
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_dup, null)
{
    dataframe_t *df = df_dup(NULL);

    cr_assert_eq(df != NULL, FALSE, "Dataframe hasn't returned proper pointer (Got %p)", df);
    df_free(df);
}
