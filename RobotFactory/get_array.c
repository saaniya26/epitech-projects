/*
** EPITECH PROJECT, 2025
** raz
** File description:
** saniy
*/

#include "include/my.h"

int get_file_height(char const *buffer)
{
    int height = 0;

    for (int cont = 0; buffer[cont] != '\0'; cont++)
        if (buffer[cont] == '\n')
            height++;
    return (height);
}

static char **allocate_map(int size, FILE *stream)
{
    char **map;

    map = malloc(sizeof(char *) * size);
    if (!map) {
        fclose(stream);
        return NULL;
    }
    return map;
}

static int process_line(char **map, char *line, int cont)
{
    map[cont] = my_strdup(line);
    if (!map[cont]) {
        return 84;
    }
    if (map[cont][my_strlen(map[cont]) - 1] == '\n')
        map[cont][my_strlen(map[cont]) - 1] = '\0';
    change_letters(map[cont], '#', 0);
    return 0;
}

static int read_lines(char **map, FILE *stream)
{
    char *line;
    size_t len;
    ssize_t nread;
    int cont;

    line = NULL;
    len = 0;
    cont = 0;
    nread = getline(&line, &len, stream);
    while (nread != -1) {
        if (process_line(map, line, cont) == 84) {
            liberez_lakrim(map);
            fclose(stream);
            return 84;
        }
        cont++;
        nread = getline(&line, &len, stream);
    }
    map[cont] = NULL;
    return 0;
}

char **get_array(char *filepath, char *buffer)
{
    int x;
    FILE *stream;
    char **map;

    x = get_file_height(buffer) + 1;
    stream = fopen(filepath, "r");
    if (!stream)
        return NULL;
    map = allocate_map(x, stream);
    if (!map)
        return NULL;
    if (read_lines(map, stream) == 84)
        return NULL;
    fclose(stream);
    return map;
}

uint16_t swap_16(uint16_t value)
{
    return (value >> 8) | (value << 8);
}

uint32_t swap_32(uint32_t value)
{
    return ((value >> 24) & 0xFF) |
            ((value >> 8) & 0xFF00) |
            ((value << 8) & 0xFF0000) |
            ((value << 24) & 0xFF000000);
}
