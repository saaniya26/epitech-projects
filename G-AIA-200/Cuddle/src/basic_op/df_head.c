/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_head
*/

#include <stdlib.h>
#include "dataframe.h"
#include "df_core/df_line.h"
#include "my.h"
#include "my_printf.h"

static int patch_head(dataframe_line_t *head_line)
{
    if (head_line == NULL)
        return FUNC_FAILED;
    df_line_destroy(head_line->next);
    head_line->next = NULL;
    return FUNC_SUCCESS;
}

dataframe_t *df_head(dataframe_t *dataframe, int nb_rows)
{
    int index = 1;
    dataframe_t *head = NULL;
    dataframe_line_t *line = NULL;

    if (dataframe == NULL || nb_rows <= 0)
        return NULL;
    head = df_dup(dataframe);
    if (head == NULL)
        return df_free_n(head);
    line = head->lines;
    if (line == NULL)
        return df_free_n(head);
    for (; line->next != NULL && index != nb_rows;
        line = line->next)
        index++;
    if (patch_head(line) == FUNC_FAILED)
        return df_free_n(head);
    return head;
}
