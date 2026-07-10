/*
** EPITECH PROJECT, 2024
** Repos
** File description:
** my_ls_a
*/

#include "myls.h"

int my_ls_a(char *filename)
{
    struct dirent *d;
    DIR *dir;

    dir = opendir(filename);
    if (dir == NULL) {
        perror("ls");
        exit(84);
    }
    d = readdir(dir);
    while (d != NULL) {
        mini_printf("%s\n", d->d_name);
        d = readdir(dir);
    }
    closedir(dir);
    return 0;
}
