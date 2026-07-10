/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** new_hashtable.c
*/

#include "hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable;

    if (hash == NULL || len <= 0)
        return NULL;
    hashtable = malloc(sizeof(hashtable_t));
    if (hashtable == NULL)
        return NULL;
    hashtable->hash = hash;
    hashtable->size = len;
    hashtable->table = malloc(sizeof(hashtable_node_t *) * len);
    if (hashtable->table == NULL) {
        free(hashtable);
        return NULL;
    }
    for (int i = 0; i < len; i++)
        hashtable->table[i] = NULL;
    return hashtable;
}
