/*
** EPITECH PROJECT, 2024
** Documents
** File description:
** settingup
*/

#ifndef SETTINGUP_H_
    #define SETTINGUP_H_
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <ctype.h>
    #include <stdlib.h>
typedef struct square {
    int row;
    int col;
    int max;
    int max_i;
    int max_j;
    char **map;
} square_t;
int my_getnbr(char const *str);
int verification(int *nbr, char const *str, int i);
int number(int *nbr, char const *str, int i);
int my_put_nbr(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
char **my_str_to_word_array(char const *str);
int my_count_word(char const *str);
int my_strlen(char const *str, int k);
int my_strlen_original(char const *str);
int fs_open_file(char const *filepath, square_t *square);
int check(square_t *square);
void find_square(int i, int j, square_t *square, int **matrice);
int find_smallest(int a, int b, int c);
int change(square_t *square);
int count_col(square_t *square);
int exclude_num(int i, const char *str);
int print_map(square_t *square);
int pattern_index(int k, int len);
void generate(square_t *square, int dimension, int len, char *pattern);
int error_generate(char **argv, square_t *square);
#endif /* !SETTINGUP_H_ */
