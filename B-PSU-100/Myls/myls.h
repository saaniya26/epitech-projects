/*
** EPITECH PROJECT, 2024
** B-PSU-100
** File description:
** myls
*/

#ifndef MYLS_H_
    #define MYLS_H_
    #include <dirent.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <time.h>
typedef struct flags {
    bool is_a;
    bool is_l;
} flags_t;
void my_putchar(char c);
void boucle(struct dirent *d, DIR *dir, flags_t *flags);
char *condition(char *file, struct dirent *d);
char *my_strcat(char const *a, char const *b);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_switch_case(char s, va_list str);
int mini_printf(const char *format, ...);
int my_ls(char *filename, flags_t *flags);
int my_ls_l(char *file);
int my_ls_a(char *filename);
static void my_block(struct dirent *d, long *count, char *str);
int flag(char *argv, int i, flags_t *flags);
void getflag(int argc, char **argv, flags_t *flags);
int total(char *file);
int display(struct dirent *d, long *count, char *str);
char *displ_time(char *time);
int filetype(mode_t m);
int filetype2(mode_t m);
int file_perm(mode_t m);
int parsing(int argc, char **argv, flags_t *flags);
#endif /* !MYLS_H_ */
