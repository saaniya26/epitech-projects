/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** hash.c
*/

#include "hashtable.h"

int hash(char *key, int len)
{
    int h_val = 0;

    if (key == NULL)
        return 84;
    for (int i = 0; key[i] != '\0'; i++) {
        h_val = h_val * 31 + (key[i] / 2);
    }
    if (h_val < 0) {
        h_val = h_val * (-1);
    }
    return h_val;
}
