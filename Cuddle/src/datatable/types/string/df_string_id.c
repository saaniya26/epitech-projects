/*
** EPITECH PROJECT, 2025
** df_string_id
** File description:
** Cuddle
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t df_string_id(const char *string)
{
    if (string == NULL)
        return FALSE;
    return string[0] != '\0';
}
