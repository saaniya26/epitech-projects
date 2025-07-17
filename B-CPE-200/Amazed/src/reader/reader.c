/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-amazed-liam.colle
** File description:
** reader
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "getline.h"
#include "my.h"
#include "utils.h"

static void remove_backslash(char *string)
{
    if (string == NULL)
        return;
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] == '\n' && string[i + 1] == '\0')
            string[i] = '\0';
}

static char **read_data(FILE *file, size_t *size)
{
    char **data = NULL;
    char *temp_ptr = NULL;

    if (file == NULL || size == NULL)
        return NULL;
    data = malloc(sizeof(char *) * 1);
    if (data == NULL)
        return NULL;
    data[0] = NULL;
    for (int i = 1; getline(&temp_ptr, size, file) != FUNC_FAILED;
        i++) {
        data = (char **) my_realloc_tab((void **) data, i, i + 1,
            sizeof(char *));
        if (data == NULL)
            return NULL;
        data[i - 1] = temp_ptr;
        temp_ptr = NULL;
    }
    free(temp_ptr);
    return data;
}

char **am_reader(void)
{
    size_t size = 0;
    char **data = read_data(stdin, &size);

    if (data == NULL)
        return NULL;
    for (int i = 0; data[i] != NULL; i++)
        remove_backslash(data[i]);
    return data;
}
