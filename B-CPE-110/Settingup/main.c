/*
** EPITECH PROJECT, 2024
** Documents
** File description:
** main
*/

#include "settingup.h"

int main(int argc, char **argv)
{
    struct stat s;
    square_t *square = malloc(sizeof(square_t));
    int error = 0;

    if (argc == 2) {
        if (stat(argv[1], &s) == -1) {
            return (84);
        } else {
            error = fs_open_file(argv[1], square);
        }
    }
    if (argc == 3) {
        error = error_generate(argv, square);
    }
    if (argc > 3) {
        return 84;
    }
    return error;
}
