/*
** EPITECH PROJECT, 2024
** Repos
** File description:
** cases
*/

#include "myls.h"

int filetype2(mode_t m)
{
    switch (m & __S_IFMT) {
        case __S_IFLNK:
            my_putchar('l');
            break;
        case __S_IFSOCK:
            my_putchar('s');
            break;
    }
}

int filetype(mode_t m)
{
    switch (m & __S_IFMT) {
        case __S_IFREG:
            my_putchar('-');
            break;
        case __S_IFDIR:
            my_putchar('d');
            break;
        case __S_IFBLK:
            my_putchar('b');
            break;
        case __S_IFCHR:
            my_putchar('c');
            break;
        case __S_IFIFO:
            my_putchar('p');
            break;
        default:
            filetype2(m);
    }
}

int file_perm(mode_t m)
{
    mini_printf("%c", (m & S_IRUSR) ? 'r' : '-');
    mini_printf("%c", (m & S_IWUSR) ? 'w' : '-');
    mini_printf("%c", (m & S_IXUSR) ? 'x' : '-');
    mini_printf("%c", (m & S_IRGRP) ? 'r' : '-');
    mini_printf("%c", (m & S_IWGRP) ? 'w' : '-');
    mini_printf("%c", (m & S_IXGRP) ? 'x' : '-');
    mini_printf("%c", (m & S_IROTH) ? 'r' : '-');
    mini_printf("%c", (m & S_IWOTH) ? 'w' : '-');
    mini_printf("%c", (m & S_IXOTH) ? 'x' : '-');
}
