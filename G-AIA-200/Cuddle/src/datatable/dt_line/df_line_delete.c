/*
** EPITECH PROJECT, 2025
** df_line_delete
** File description:
** Cuddle
*/

#include <stdio.h>
#include "df_core/df_core.h"
#include "df_core/df_line.h"
#include "utils.h"

int df_line_delete(dataframe_line_t *line)
{
    dataframe_t *dt = NULL;

    if (line == NULL)
        return FUNC_FAILED;
    dt = line->dt;
    if (dt == NULL)
        return FUNC_FAILED;
    if (line->prev != NULL)
        line->prev->next = line->next;
    if (line->next != NULL)
        line->next->prev = line->prev;
    if (dt->lines == line)
        dt->lines = line->next;
    dt->nb_rows--;
    df_line_free(line);
    return FUNC_SUCCESS;
}
