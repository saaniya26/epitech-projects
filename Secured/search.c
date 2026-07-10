/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** search.c
*/

#include "hashtable.h"

char *ht_search(hashtable_t *ht, char *key)
{
    int index;
    hashtable_node_t *current;

    if (ht == NULL || key == NULL)
        return NULL;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->table[index];
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}
