/*
** EPITECH PROJECT, 2020
** B-CPE-110-RUN-1-1-pushswap-mathieu.muty
** File description:
** free_list.c
*/

#include "../include/push.h"
#include "../include/my.h"

void free_list(node_t **head)
{
    node_t *prev = NULL;

    while (prev != NULL) {
        prev = (*head);
        *head = (*head)->next;
        free(head);
    }
}