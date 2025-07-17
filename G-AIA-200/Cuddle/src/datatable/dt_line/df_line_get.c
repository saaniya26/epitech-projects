/*
** EPITECH PROJECT, 2025
** df_line_len
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_line.h"
#include "utils.h"

dataframe_line_t *df_line_get(dataframe_line_t *line, int i)
{
    int index = 0;

    if (line == NULL || (i < 0 && i != -1))
        return NULL;
    if (i == -1) {
        for (; line->next != NULL; line = line->next);
        return line;
    }
    for (; line->next != NULL && index != i; line = line->next)
        index++;
    return line;
}
