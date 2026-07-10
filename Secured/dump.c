/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** dump.c
*/

#include "hashtable.h"

void ht_dump(hashtable_t *ht)
{
    hashtable_node_t *current;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        mini_printf("[%d]:\n", i);
        current = ht->table[i];
        while (current != NULL) {
            mini_printf("> %d - %s\n", ht->hash(current->key, ht->size),
            current->value);
            current = current->next;
        }
    }
}
