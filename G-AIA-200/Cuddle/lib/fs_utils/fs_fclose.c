/*
** EPITECH PROJECT, 2025
** fs_fclose
** File description:
** fs_utils
*/

#include <stdio.h>
#include "utils.h"

int fs_fclose(FILE *stream)
{
    if (stream == NULL)
        return FUNC_FAILED;
    return fclose(stream);
}
