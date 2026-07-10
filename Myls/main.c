/*
** EPITECH PROJECT, 2024
** B-PSU-100
** File description:
** main
*/

#include "myls.h"

int main(int argc, char **argv)
{
    int error = 0;
    flags_t *flags = malloc(sizeof(flags_t));

    getflag(argc, argv, flags);
    if (argc == 1) {
        my_ls(".", flags);
    } else {
        parsing(argc, argv, flags);
    }
    free(flags);
    if (error == 84)
        exit(84);
    return 0;
}
