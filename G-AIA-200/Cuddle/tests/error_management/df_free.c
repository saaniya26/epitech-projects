/*
** EPITECH PROJECT, 2025
** df_free
** File description:
** Cuddle
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "dataframe.h"
#include "utils.h"

Test(err_mgmt_free, null)
{
    dataframe_t *df = NULL;

    df_free(df);
}
