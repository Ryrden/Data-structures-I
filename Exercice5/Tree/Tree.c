#include "Tree.h"
#include <stdlib.h>
#include "../Bank/Bank.h"

typedef struct node_st NODE;

struct node_st {
    void *item;
    NODE *right;
    NODE *left;
};

struct tree_st {
    NODE *root;
    int depth;
};

static void recursion_pre_order(NODE *root);
static void recursion_in_order(NODE *root);
static void recursion_pos_order(NODE *root);
static void erase_tree_nodes(NODE **root)

TREE *create_tree() {
    TREE *tree;
    tree = (TREE *)malloc(sizeof(TREE));
    if (tree != NULL) {
        tree->root = NULL;
        tree->depth = -1;
        return tree;
    }
    return NULL;
}

NODE *create_tree_node(void *item) {
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

void pre_order_tree(TREE *tree) {
    recursion_pre_order(tree->root);
}

void in_order_tree(TREE *tree) {
    recursion_in_order(tree->root);
}

void pos_order_tree(TREE *tree) {
    recursion_pos_order(tree->root);
}

boolean insert_tree(TREE *tree, void *item, int side, int key) {
    if (tree->root == NULL)
        return ((tree->root = create_tree_node(item)) != NULL);
    else
        return ((tree->root = insert_tree_node(tree, item, side, key)));
}

NODE insert_tree_node(NODE *root, void *item, int side, int key) {
    if (root != NULL) {
        root->left = insert_tree_node(root->left, item, side, key);
        root->right = insert_tree_node(root->right, item, side, key);
        if (key == get_key(item)) {
            if (side == LEFT && root->left == NULL)
                root->left = create_tree_node(item);
            else if (side == RIGHT && root->right == NULL)
                root->right = create_tree_node(item);
        }
    }
    return root;
}

boolean erase_tree(TREE **tree) {
    if (*tree != NULL) {
        erase_tree_nodes(&tree->root);
        return TRUE;
    }
    return FALSE
}


static void erase_tree_nodes(NODE **root) {
    if (root != NULL) {
        erase_tree_nodes(&root->left);
        erase_tree_nodes(&root->right);
        free(&root);
    }
}

static void recursion_pre_order(NODE *root) {
    if (root != NULL) {
        print_item(root->item);
        recursion_pre_order(root->left);
        recursion_pre_order(root->right);
    }
}

static void recursion_in_order(NODE *root) {
    if (root != NULL) {
        print_item(root->item);
        recursion_in_order(root->left);
        recursion_in_order(root->right);
    }
}

static void recursion_pos_order(NODE *root) {
    if (root != NULL) {
        print_item(root->item);
        recursion_pos_order(root->left);
        recursion_pos_order(root->right);
    }
}
