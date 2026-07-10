/*
** EPITECH PROJECT, 2025
** B-PSU-200
** File description:
** my_is_alpha
*/

#include "../include/my.h"

int my_isalnum(int c)
{
    if (my_isalpha(c) || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

int my_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}
