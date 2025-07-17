/*
** EPITECH PROJECT, 2025
** df_bool_id
** File description:
** Cuddle
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t df_bool_id(const char *string)
{
    const char *allowed[] = {"true", "false",
        "True", "False", "TRUE", "FALSE", NULL};

    if (string == NULL)
        return FALSE;
    return my_isin(string, allowed);
}
