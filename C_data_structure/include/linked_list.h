/*
** MATT_TEK, 2021
** header
** File description:
** header file for linked list
*/

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node_s
{
    int data_value;
    struct node_s *next;
} node_int_t;

typedef struct node_s
{
    char *data_value;
    struct node_s *next;
} node_str_t;

typedef struct node_s
{
    char data_value;
    struct node_s *next;
} node_char_t;

#endif