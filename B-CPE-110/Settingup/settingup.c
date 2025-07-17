/*
** EPITECH PROJECT, 2024
** settingup
** File description:
** settingup
*/

#include "settingup.h"

int error_generate(char **argv, square_t *square)
{
    int dimension = my_getnbr(argv[1]);
    char *pattern = argv[2];
    int len = my_strlen_original(pattern);

    if (dimension <= 0 || pattern[0] == '\0') {
        return 84;
    }
    for (int i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != '.' || pattern[i] != 'o') {
            return 84;
        }
    }
    generate(square, dimension, len, pattern);
    return 0;
}

void generate(square_t *square, int dimension, int len, char *pattern)
{
    int k = 0;
    int j;
    char **gen_map = malloc(sizeof(char *) * (dimension + 1));

    for (int i = 0; i < dimension; i++) {
        gen_map[i] = malloc(sizeof(char) * (1 + dimension));
        for (j = 0; j < dimension; j++) {
            gen_map[i][j] = pattern[k];
            k++;
            k = pattern_index(k, len);
        }
        gen_map[i][j] = '\0';
    }
    gen_map[dimension] = NULL;
    square->map = gen_map;
    square->row = dimension;
    square->col = dimension;
    check(square);
    free(gen_map);
}

int fs_open_file(char const *filepath, square_t *square)
{
    struct stat s;
    int fd = 0;
    char *buffer;

    stat(filepath, &s);
    buffer = malloc(sizeof(char) * s.st_size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return 84;
    read(fd, buffer, s.st_size);
    square->row = my_getnbr(buffer);
    square->map = my_str_to_word_array(buffer);
    square->col = count_col(square);
    close(fd);
    check(square);
    free(square->map);
}
