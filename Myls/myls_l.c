/*
** EPITECH PROJECT, 2024
** B-PSU-100
** File description:
** myls-l
*/

#include "myls.h"

char *displ_time(char *time)
{
    int i = 4;
    int j = 0;
    char *str = malloc(sizeof(char) * 12);

    while (i < 16) {
        str[j] = time[i];
        j++;
        i++;
    }
    str[12] = '\0';
    return str;
    free(str);
}

static void my_block(struct dirent *d, long *count, char *str)
{
    struct stat s;

    stat(str, &s);
    *count += (s.st_blocks);
}

int total(char *file)
{
    long count = 0;
    struct dirent *d;
    DIR *dir = NULL;
    char *str = NULL;
    struct stat s;

    dir = opendir(file);
    d = readdir(dir);
    while (d != NULL) {
        if (d->d_name[0] != '.')
            str = condition(file, d);
            my_block(d, &count, str);
        d = readdir(dir);
    }
    mini_printf("total %d\n", count / 2);
    closedir(dir);
}

int display(struct dirent *d, long *count, char *str)
{
    DIR *dir;
    struct stat s;
    struct passwd *pwd;
    struct group *grp;
    char *time;

    if (stat(str, &s) == -1)
        exit(84);
    pwd = getpwuid(s.st_uid);
    grp = getgrgid(s.st_gid);
    time = ctime(&s.st_mtime);
    filetype(s.st_mode);
    file_perm(s.st_mode);
    mini_printf(" %d ", s.st_nlink);
    mini_printf("%s ", pwd->pw_name);
    mini_printf("%s ", grp->gr_name);
    mini_printf("%d ", s.st_size);
    mini_printf("%s ", displ_time(time));
    mini_printf("%s", str);
    my_putchar('\n');
}

char *condition(char *file, struct dirent *d)
{
    char *cat = NULL;

    if (file[my_strlen(file) -1] == '/') {
        cat = my_strcat(file, d->d_name);
    } else {
        cat = my_strcat(my_strcat(file, "/"), d->d_name);
    }
    return cat;
}

int my_ls_l(char *file)
{
    struct dirent *d;
    DIR *dir = NULL;
    long count = 0;
    char *str = NULL;

    dir = opendir(file);
    if (dir == NULL) {
        perror("ls");
        exit(84);
    }
    total(file);
    d = readdir(dir);
    while (d != NULL) {
        if (d->d_name[0] != '.') {
            str = condition(file, d);
            display(d, &count, str);
        }
        d = readdir(dir);
    }
    closedir(dir);
}
