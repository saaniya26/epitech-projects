/*
** EPITECH PROJECT, 2025
** df_uint_id
** File description:
** Cuddle
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t df_uint_id(const char *string)
{
    if (string == NULL)
        return FALSE;
    return my_str_isnum(string);
}
