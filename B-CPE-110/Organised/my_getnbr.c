/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** #################
*/

#include <stdio.h>

int number(int *nbr, char const *str, int i)
{
    float test = *nbr;

    if (str[i] >= '0' && str[i] <= '9') {
        test = test * 10 + (str[i] - '0');
        if (test > 2147483647) {
            return 2;
        }
        *nbr = *nbr * 10 + (str[i] - '0');
        return 1;
    }
    return 0;
}

int verification(int *nbr, char const *str, int i)
{
    int j = 0;

    j = number(&*nbr, str, i);
    if (j == 1 && str[i + 1] < '0' || str[i + 1] > '9' && j == 1) {
        return 1;
    } else if (j == 2) {
        return 2;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; str[i] != '\0' && j < 1; i++) {
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            k = 1;
        }
        j = verification(&nbr, str, i);
    }
    if (k == 1) {
        nbr = nbr * -1;
    }
    if (j == 2) {
        return 0;
    }
    return nbr;
}
