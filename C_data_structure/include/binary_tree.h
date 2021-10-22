#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct btree {
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;

btree_t *btree_create_node(void *item);
void free_tree(btree_t *root);
int compare_int(btree_t *tree, void *data);
void insert_in_order(btree_t **root, void *new, int (*cmp)(btree_t *, void *));
void insert_post_order(btree_t **root, void *new, int (*cmp)(btree_t *, void *));
void btree_apply_prefix(btree_t *root, int (*applyf)(void *));
int print_int_voidstar(void *data);

#endif /* !BINARY_TREE_H_ */
