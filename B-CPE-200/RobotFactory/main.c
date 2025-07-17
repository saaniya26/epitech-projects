/*
** EPITECH PROJECT, 2025
** raz
** File description:
** saniy
*/

#include "include/my.h"

int prems(char *str, char letter)
{
    char *pos = strchr(str, letter);

    return (pos) ? (pos - str) : 0;
}

void clean(char *str)
{
    for (; *str; str++)
        if (*str == '\t')
            *str = ' ';
}

void liberez_lakrim(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

int trad(file_t *file)
{
    FILE *fl = fopen(file->filename, "wb");

    if (!fl)
        return -1;
    fwrite(file->header, sizeof(header_t), 1, fl);
    add_command(file, fl);
    fclose(fl);
    free(file->header);
    return 0;
}

int main(int ac, char **av)
{
    file_t *file = NULL;

    if (ac != 2) {
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        display_usage();
        return 0;
    }
    if (handle_errors(ac, av, file) != 0) {
        free(file);
        return 84;
    }
    if (parse(file, av[1]) != 84) {
        trad(file);
        free(file);
        return 0;
    }
    free(file);
    return 84;
}
