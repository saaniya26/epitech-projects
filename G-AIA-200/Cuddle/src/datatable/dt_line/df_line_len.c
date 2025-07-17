/*
** EPITECH PROJECT, 2025
** df_line_len
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_line.h"
#include "utils.h"

int df_line_len(dataframe_line_t *line)
{
    int len = 0;

    if (line == NULL)
        return FUNC_FAILED;
    for (; line != NULL; line = line->next)
        len++;
    return len;
}
