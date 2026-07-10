/*
** EPITECH PROJECT, 2025
** df_describe
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_describe, null)
{
    dataframe_t *df = NULL;

    df_describe(df);
}
