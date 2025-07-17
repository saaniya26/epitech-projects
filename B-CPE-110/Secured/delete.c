/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** delete.c
*/

#include "hashtable.h"

int cut(hashtable_node_t *current, hashtable_node_t *prev,
    hashtable_t *ht, int index)
{
    if (prev == NULL)
        ht->table[index] = current->next;
    else
        prev->next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index;
    hashtable_node_t *current;
    hashtable_node_t *prev;

    if (ht == NULL || key == NULL)
        return 84;
    index = ht->hash(key, ht->size) % ht->size;
    current = ht->table[index];
    prev = NULL;
    while (current != NULL) {
        if (my_strcmp(current->key, key) == 0) {
            cut(current, prev, ht, index);
        }
        prev = current;
        current = current->next;
    }
    return 84;
}
