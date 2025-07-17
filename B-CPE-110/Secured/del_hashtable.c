/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** del_hashtable.c
*/

#include "hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    hashtable_node_t *current;
    hashtable_node_t *temp;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        current = ht->table[i];
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
