/*
** EPITECH PROJECT, 2024
** B-CPE-110-MAR-1-1-secured-saaniya.perally
** File description:
** insert.c
*/

#include "hashtable.h"

hashtable_node_t *find_node(hashtable_node_t *head, char *key)
{
    while (head != NULL) {
        if (my_strcmp(head->key, key) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

hashtable_node_t *create_node(char *key, char *value)
{
    hashtable_node_t *new_node = malloc(sizeof(hashtable_node_t));

    if (new_node == NULL)
        return NULL;
    new_node->key = my_strdup(key);
    if (new_node->key == NULL) {
        free(new_node);
        return NULL;
    }
    new_node->value = my_strdup(value);
    if (new_node->value == NULL) {
        free(new_node->key);
        free(new_node);
        return NULL;
    }
    new_node->next = NULL;
    return new_node;
}

int cut_out(hashtable_node_t *node, char *value)
{
    if (node != NULL) {
        free(node->value);
        node->value = my_strdup(value);
        if (node->value == NULL) {
            return 84;
        }
        return 0;
    }
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hashtable_node_t *node;
    hashtable_node_t *new_node;
    int index;

    if (ht == NULL || key == NULL || value == NULL) {
        return 84;
    }
    index = ht->hash(key, ht->size) % ht->size;
    node = find_node(ht->table[index], key);
    cut_out(node, value);
    new_node = create_node(key, value);
    if (new_node == NULL) {
        return 84;
    }
    new_node->next = ht->table[index];
    ht->table[index] = new_node;
    return 0;
}
