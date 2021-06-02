/*
** MATT_TEK, 2021
** list.cj
** File description:
** all function to manage linked list
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/linked_list.h"

void my_put_list(node_int_t **head, node_int_t *new)
{
    if (new == NULL)
        return;
    new->next = *head;
    *head = new;
}

node_int_t *create_node(int data_value)
{
    node_int_t *node = malloc(sizeof(node_int_t));
    node->data_value = data_value;
    node->next = NULL;
    return (node);
}

void my_print_list(node_int_t *next)
{
    for (; next != NULL; next->next)
        printf("[%d]", next->data_value);    
}