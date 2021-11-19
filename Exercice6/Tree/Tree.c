#include "Tree.h"
#include <stdlib.h>

typedef struct node_st NODE;

struct node_st {
    void *item;
    NODE *right;
    NODE *left;
};

struct binary_tree_st {
    NODE *root;
    int depth;
};

static void recursion_pre_order(NODE *root);
static void recursion_in_order(NODE *root);
static void recursion_pos_order(NODE *root);
static void erase_tree_nodes(NODE **root);
static NODE *create_tree_node(void *item);
static NODE *insert_tree_node(NODE *root, void *item);
static boolean isBigger(void *item, NODE *root);
static boolean isSmaller(void *item, NODE *root);
static boolean least_one_child(NODE *root);
static boolean has_both_childs(NODE *root);
static BANK *search_node(NODE *root, TYPE_KEY key);

BINARY_TREE *create_tree() {
    BINARY_TREE *tree;
    tree = (BINARY_TREE *)malloc(sizeof(BINARY_TREE));
    if (tree != NULL) {
        tree->root = NULL;
        tree->depth = -1;
        return tree;
    }
    return NULL;
}

static NODE *create_tree_node(void *item) {
    if (item != NULL) {
        NODE *new_item;
        new_item = (NODE *)malloc(sizeof(NODE));
        if (new_item == NULL)
            exit(EXIT_FAILURE);
        new_item->item = item;
        new_item->left = NULL;
        new_item->right = NULL;
        return new_item;
    }
    return NULL;
}

boolean erase_tree(BINARY_TREE **tree) {
    if (tree != NULL) {
        erase_tree_nodes(&(*tree)->root);
        free(*tree);
        tree = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean insert_tree(BINARY_TREE *tree, void *item) {
    return ((tree->root = insert_tree_node(tree->root, item)) != NULL);
}

static NODE *insert_tree_node(NODE *root, void *item) {
    if (root == NULL)
        root = create_tree_node(item);
    else if (isBigger(item, root))
        root->right = insert_tree_node(root->right, item);
    else if (isSmaller(item, root))
        root->left = insert_tree_node(root->left, item);
    return root;
}

static boolean isBigger(void *item, NODE *root) {
    return get_key(item) > get_key(root->item);
}
static boolean isSmaller(void *item, NODE *root) {
    return get_key(item) < get_key(root->item);
}

static void erase_tree_nodes(NODE **root) {
    if (*root != NULL) {
        erase_tree_nodes(&(*root)->left);
        erase_tree_nodes(&(*root)->right);
        free((*root)->item);
        (*root)->item = NULL;
        free(*root);
        root = NULL;
    }
}

void pre_order_tree(BINARY_TREE *tree) {
    recursion_pre_order(tree->root);
}

static void recursion_pre_order(NODE *root) {
    if (root != NULL) {
        print_item(root->item);
        recursion_pre_order(root->left);
        recursion_pre_order(root->right);
    }
}

void in_order_tree(BINARY_TREE *tree) {
    recursion_in_order(tree->root);
}

static void recursion_in_order(NODE *root) {
    if (root != NULL) {
        recursion_in_order(root->left);
        print_item(root->item);
        recursion_in_order(root->right);
    }
}

void pos_order_tree(BINARY_TREE *tree) {
    recursion_pos_order(tree->root);
}

static void recursion_pos_order(NODE *root) {
    if (root != NULL) {
        recursion_pos_order(root->left);
        recursion_pos_order(root->right);
        print_item(root->item);
    }
}

BANK *search_tree(BINARY_TREE *tree, TYPE_KEY key) {
    return (search_node(tree->root, key));
}

static BANK *search_node(NODE *root, TYPE_KEY key) {
    if (root == NULL)
        return NULL;
    if (key == get_key(root->item))
        return (root->item);
    if (key < get_key(root->item))
        return (search_node(root->left, key));
    else
        return search_node(root->right, key);
}

boolean remove_tree(BINARY_TREE *tree, TYPE_KEY key) {
    if (tree != NULL)
        return remove_node(&tree->root, key);
    return FALSE;
}

static boolean least_one_child(NODE *root) {
    return (*root)->left == NULL || (*root)->right == NULL;
}

static boolean has_both_childs(NODE *root) {
    return (*root)->left != NULL && (*root)->right != NULL;
}

static boolean remove_node(NODE **root, TYPE_KEY key) {
    NODE *removed_node;
    if (*root == NULL)
        return FALSE;

    if (key == item_get_key((*root)->item)) {
        if (least_one_child(root)) {
            removed_node = *root;
            if ((*root)->left == NULL)
                *root = (*root)->right;
            else
                *root = (*root)->left;

            free(removed_node);
            removed_node = NULL;
        } else if (has_both_childs(root))
            swap_min_right((*root)->right, (*root), (*root));

        return TRUE;
    } else {
        if (key < item_get_key((*root)->item))
            return remove_node(&(*root)->left, key);
        else
            return remove_node(&(*root)->right, key);
    }
}

static void swap_min_right(NODE *swap, NODE *root, NODE *previous_node) {
    if (swap->left != NULL) {
        swap_min_right(swap->left, root, swap);
        return;
    }
    if (root == previous_node)
        previous_node->left = swap->left;
    else
        previous_node->right = swap->left;

    root->item = swap->item;
    free(swap);
    swap = NULL;
}