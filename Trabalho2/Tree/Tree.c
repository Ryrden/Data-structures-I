#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_st NODE;

struct node_st {
    GAME *item;
    NODE *right;
    NODE *left;
    int height;
};

struct avl_tree_st {
    NODE *root;
    int depth;
};

static void recursion_pre_order(NODE *root);
static void recursion_in_order(NODE *root);
static void recursion_pos_order(NODE *root);

static NODE *create_tree_node(GAME *item);
static NODE *insert_tree_node(NODE *root, GAME *item);
static NODE *insert_tree_node_and_rotate(NODE *root, GAME *item);
static NODE *execute_tree_rotate(NODE *root, GAME *item);
static void erase_tree_nodes(NODE **root);

static boolean positive_unbalance(NODE *root);
static boolean negative_unbalance(NODE *root);
static boolean isBigger(GAME *item, NODE *root);
static boolean isSmaller(GAME *item, NODE *root);
static boolean isEqual(GAME *item, NODE *root);
static boolean isOrdBigger(GAME *item, NODE *root);
static boolean isOrdSmaller(GAME *item, NODE *root);

static int get_node_height(NODE *root);
static int update_height(NODE *left, NODE *right);

static NODE *right_rotate(NODE *item);
static NODE *left_rotate(NODE *item);
static NODE *left_right_rotate(NODE *item);
static NODE *right_left_rotate(NODE *item);

static boolean least_one_child(NODE **root);
static boolean has_both_childs(NODE **root);

static GAME *search_node(NODE *root, TYPE_KEY key);

static void swap_max_left(NODE *swap, NODE *root, NODE *previous_node);
static NODE *remove_node(NODE **root, TYPE_KEY key);

AVL_TREE *create_tree() {
    AVL_TREE *tree;
    tree = (AVL_TREE *)malloc(sizeof(AVL_TREE));
    if (tree != NULL) {
        tree->root = NULL;
        tree->depth = -1;
    }
    return tree;
}

static NODE *create_tree_node(GAME *item) {
    if (item != NULL) {
        NODE *new_item;
        new_item = (NODE *)malloc(sizeof(NODE));
        if (new_item == NULL) {
            printf("\nError to create tree node\n");
            exit(EXIT_FAILURE);
        }
        new_item->height = 0;
        new_item->item = item;
        new_item->left = NULL;
        new_item->right = NULL;
        return new_item;
    }
    return NULL;
}

boolean erase_tree(AVL_TREE **tree) {
    if (tree != NULL) {
        erase_tree_nodes(&(*tree)->root);
        free(*tree);
        tree = NULL;
        return TRUE;
    }
    return FALSE;
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

static int get_node_height(NODE *root) {
    if (root == NULL)
        return -1;
    return root->height;
}

boolean insert_tree(AVL_TREE *tree, GAME *item) {
    tree->root = insert_tree_node_and_rotate(tree->root, item);
    return tree->root != NULL;
}

static NODE *insert_tree_node(NODE *root, GAME *item) {
    if (root == NULL)
        root = create_tree_node(item);
    else if (!isEqual(item, root)) {
        if (isBigger(item, root))
            root->right = insert_tree_node(root->right, item);
        else if (isSmaller(item, root))
            root->left = insert_tree_node(root->left, item);
    } else {
        if (isOrdBigger(item, root))
            root->right = insert_tree_node(root->right, item);
        else if (isOrdSmaller(item, root))
            root->left = insert_tree_node(root->left, item);
    }
    root->height = update_height(root->left, root->right);
    root = execute_tree_rotate(root, item);
    return root;
}

static NODE *insert_tree_node_and_rotate(NODE *root, GAME *item) {
    return insert_tree_node(root, item);
}

static NODE *execute_tree_rotate(NODE *root, GAME *item) {
    if (negative_unbalance(root)) {
        if (isSmaller(item, root->left))
            root = right_rotate(root);
        else
            root = left_right_rotate(root);

    } else if (positive_unbalance(root)) {
        if (isBigger(item, root->right))
            root = left_rotate(root);
        else
            root = right_left_rotate(root);
    }
    return root;
}

static boolean isOrdBigger(GAME *item, NODE *root) {
    char *name1 = get_game_name(item);
    char *name2 = get_game_name(root->item);

    return strcmp(name1, name2) > 0;
}

static boolean isOrdSmaller(GAME *item, NODE *root) {
    char *name1 = get_game_name(item);
    char *name2 = get_game_name(root->item);

    return strcmp(name1, name2) < 0;
}

static boolean isBigger(GAME *item, NODE *root) {
    return get_key(item) > get_key(root->item);
}

static boolean isSmaller(GAME *item, NODE *root) {
    return get_key(item) < get_key(root->item);
}

static boolean isEqual(GAME *item, NODE *root) {
    return get_key(item) == get_key(root->item);
}

static boolean negative_unbalance(NODE *root) {
    return get_node_height(root->right) - get_node_height(root->left) == -2;
}

static boolean positive_unbalance(NODE *root) {
    return get_node_height(root->right) - get_node_height(root->left) == 2;
}

void pre_order_tree(AVL_TREE *tree) {
    recursion_pre_order(tree->root);
}

static void recursion_pre_order(NODE *root) {
    if (root != NULL) {
        print_item(root->item);
        recursion_pre_order(root->left);
        recursion_pre_order(root->right);
    }
}

void in_order_tree(AVL_TREE *tree) {
    recursion_in_order(tree->root);
}

static void recursion_in_order(NODE *root) {
    if (root != NULL) {
        recursion_in_order(root->left);
        print_item(root->item);
        recursion_in_order(root->right);
    }
}

void pos_order_tree(AVL_TREE *tree) {
    recursion_pos_order(tree->root);
}

static void recursion_pos_order(NODE *root) {
    if (root != NULL) {
        recursion_pos_order(root->left);
        recursion_pos_order(root->right);
        print_item(root->item);
    }
}

GAME *search_tree(AVL_TREE *tree, TYPE_KEY key) {
    return (search_node(tree->root, key));
}

static GAME *search_node(NODE *root, TYPE_KEY key) {
    if (root == NULL)
        return NULL;
    if (key == get_key(root->item))
        return (root->item);
    if (key < get_key(root->item))
        return (search_node(root->left, key));
    else
        return search_node(root->right, key);
}

boolean remove_tree(AVL_TREE *tree, TYPE_KEY key) {
    if (tree != NULL)
        return ((tree->root = remove_node(&tree->root, key)) != NULL);
    return FALSE;
}

static boolean least_one_child(NODE **root) {
    return (*root)->left == NULL || (*root)->right == NULL;
}

static boolean has_both_childs(NODE **root) {
    return (*root)->left != NULL && (*root)->right != NULL;
}

static NODE *remove_node(NODE **root, TYPE_KEY key) {
    NODE *removed_node;
    if (*root == NULL)
        return NULL;

    if (key < get_key((*root)->item))
        (*root)->left = remove_node(&(*root)->left, key);

    else if (key > get_key((*root)->item))
        (*root)->right = remove_node(&(*root)->right, key);

    else if (key == get_key((*root)->item)) {
        if (least_one_child(&(*root))) {
            removed_node = *root;
            if ((*root)->left == NULL)
                *root = (*root)->right;
            else
                *root = (*root)->left;

            free(removed_node);
            removed_node = NULL;
        } else if (has_both_childs(&(*root)))
            swap_max_left((*root)->left, (*root), (*root));
    }
    if (*root != NULL) {
        (*root)->height = update_height((*root)->left, (*root)->right);
        if (negative_unbalance(*root)) {
            if (get_node_height((*root)->left->right) - get_node_height((*root)->left->left) <= 0)
                *root = right_rotate(*root);
            else
                *root = left_right_rotate(*root);
        } else if (positive_unbalance(*root)) {
            if (get_node_height((*root)->right->right) - get_node_height((*root)->right->left) >= 0)
                *root = left_rotate(*root);
            else
                *root = right_left_rotate(*root);
            
        }
    }
    return *root;
}

static void swap_max_left(NODE *swap, NODE *root, NODE *previous_node) {
    if (swap->right != NULL) {
        swap_max_left(swap->right, root, swap);
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

int update_height(NODE *left, NODE *right) {
    return max(get_node_height(left), get_node_height(right)) + 1;
}

static NODE *right_rotate(NODE *item) {
    NODE *item_rotated = item->left;
    item->left = item_rotated->right;
    item_rotated->right = item;

    item->height = update_height(item->left, item->right);
    item_rotated->height = update_height(item_rotated->left, item_rotated->right);

    return item_rotated;
}

static NODE *left_rotate(NODE *item) {
    NODE *item_rotated = item->right;
    item->right = item_rotated->left;
    item_rotated->left = item;

    item->height = update_height(item->left, item->right);
    item_rotated->height = update_height(item_rotated->left, item_rotated->right);

    return item_rotated;
}

static NODE *left_right_rotate(NODE *item) {
    item->left = left_rotate(item->left);
    return right_rotate(item);
}

static NODE *right_left_rotate(NODE *item) {
    item->right = right_rotate(item->right);
    return left_rotate(item);
}
