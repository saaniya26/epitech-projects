/*
** EPITECH PROJECT, 2024
** B-PSU-100
** File description:
** myls
*/

#include "myls.h"

void boucle(struct dirent *d, DIR *dir, flags_t *flags)
{
    while (d != NULL) {
        if (d->d_name[0] != '.' || flags->is_a == true) {
            mini_printf("%s  ", d->d_name);
        }
        d = readdir(dir);
    }
}

int my_ls(char *filename, flags_t *flags)
{
    struct dirent *d;
    DIR *dir;

    dir = opendir(filename);
    if (dir == NULL) {
        perror("ls");
        exit(84);
    }
    if (flags->is_l == false) {
        d = readdir(dir);
        boucle(d, dir, flags);
    } else {
        my_ls_l(filename);
    }
    closedir(dir);
    return 0;
}

int parsing(int argc, char **argv, flags_t *flags)
{
    int i;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            my_ls(argv[i], flags);
        }
        if (argv[i][0] == '-' && argc == 2) {
            my_ls(".", flags);
        }
    }
}

void getflag(int argc, char **argv, flags_t *flags)
{
    int i;

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            flag(argv[i], i, flags);
        }
    }
}

int flag(char *argv, int i, flags_t *flags)
{
    int x;

    for (x = 0; argv[x] != '\0'; x++) {
        switch (argv[x]) {
            case 'a':
                flags->is_a = true;
                break;
            case 'l':
                flags->is_l = true;
                break;
        }
    }
}
