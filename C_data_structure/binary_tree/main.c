#include "../include/binary_tree.h"
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    btree_t *tree = NULL;
    for (size_t i = 1; av[i]; i++)
        insert_in_order(&tree, (void *)atoll(av[i]), compare_int);
    btree_apply_prefix(tree, print_int_voidstar);
    free_tree(tree);
    return 0;
}