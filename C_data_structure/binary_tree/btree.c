#include "../include/binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

btree_t *btree_create_node(void *item)
{
    btree_t *btree = malloc(sizeof(btree_t));

    if (btree == NULL)
        return NULL;
    btree->item = item;
    btree->left = NULL;
    btree->right = NULL;
    return btree;
}

void free_tree(btree_t *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int compare_int(btree_t *tree, void *data)
{
    if ((long)tree->item < (long)data)
        return (-1);
    else if ((long)tree->item > (long)data)
        return 1;
    return 0;
}

void insert_in_order(btree_t **root, void *new, int (*cmp)(btree_t *, void *))
{
    if ((*root) == NULL) {
        (*root) = btree_create_node(new);
    } else if (cmp((*root), new) < 0) {
        if ((*root)->right == NULL)
            (*root)->right = btree_create_node(new);
        else
            insert_in_order(&(*root)->right, new, cmp);
    } else {
        if ((*root)->left == NULL)
            (*root)->left = btree_create_node(new);
        else
            insert_in_order(&(*root)->left, new, cmp);
    }
}

void insert_post_order(btree_t **root, void *new, int (*cmp)(btree_t *, void *))
{
    if ((*root) == NULL) {
        (*root) = btree_create_node(new);
    } else if (cmp(*root, new) < 0) {
        if ((*root)->left == NULL)
            (*root)->left = btree_create_node(new);
        else
            insert_in_order(&(*root)->left, new, cmp);
    } else {
        if ((*root)->right == NULL)
            (*root)->right = btree_create_node(new);
        else
            insert_in_order(&(*root)->right, new, cmp);
    }
}

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    if (root == NULL)
        return;
    applyf(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}

int print_int_voidstar(void *data)
{
    return printf("%ld\n", (long)data);
}