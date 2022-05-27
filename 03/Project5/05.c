#include <stdio.h>

typedef struct rbnode {
    int data;
    int color; // 0 : black, 1 : red

    struct rbnode* parent;
    struct rbnode* left;
    struct rbnode* right;
} rbnode;

typedef struct rbtree {
    rbnode* root;
    rbnode* NIL;
} rbtree;

rbnode* make_node(int data) {
    rbnode* node = malloc(sizeof(rbnode));

    node->data = data;
    node->color = 1;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

rbtree* make_tree() {
    rbtree* tree = malloc(sizeof(rbtree));
    rbnode* nil = malloc(sizeof(rbnode));

    nil->data = 0;
    nil->color = 0;
    nil->parent = NULL;
    nil->left = NULL;
    nil->right = NULL;
    
    tree->NIL = nil;
    tree->root = tree->NIL;

    return tree;
}

void rb_rotate_left(rbtree* tree, rbnode* parent) {
    rbnode* newparent = parent->right;
    parent->right = newparent->left;

    if (newparent->left != tree->NIL)
        (newparent->left)->parent = parent;
    newparent->parent = parent->parent;

    if (parent->parent == tree->NIL)
        tree->root = newparent;
    else {
        if (parent == (parent->parent)->left)
            (parent->parent)->left = newparent;
        else
            (parent->parent)->right = newparent;
    }
    newparent->left = parent;
    parent->parent = newparent;
}

void rb_rotate_right(rbtree* tree, rbnode* parent) {
    rbnode* newparent = parent->left;
    parent->left = newparent->right;

    if (newparent->right != tree->NIL)
        (newparent->right)->parent = parent;
    newparent->parent = parent->parent;

    if (parent->parent == tree->NIL)
        tree->root = newparent;
    else {
        if (parent == (parent->parent)->left)
            (parent->parent)->left = newparent;
        else
            (parent->parent)->right = newparent;
    }
    newparent->right = parent;
    parent->parent = newparent;
}

void rb_check_rule(rbtree* tree, rbnode* node) {
    while (node->parent->color == 1) {
        if (node->parent == ((node->parent)->parent)->left) {
            rbnode* uncle = ((node->parent)->parent)->right;

            if (uncle->color == 1) {
                (node->parent)->color = 0;
                uncle->color = 0;
                ((node->parent)->parent)->color = 1;
                node = (node->parent)->parent;
            }
            else {
                if (node == (node->parent)->right) {
                    node = node->parent;
                    rb_rotate_left(tree, node);
                }
                (node->parent)->color = 0;
                ((node->parent)->parent)->color = 1;
                rb_rotate_right(tree, (node->parent)->parent);
            }
        }
        else {
            rbnode* uncle = ((node->parent)->parent)->left;

            if (uncle->color == 1) {
                (node->parent)->color = 0;
                uncle->color = 0;
                ((node->parent)->parent)->color = 1;
                node = (node->parent)->parent;
            }
            else {
                if (node == (node->parent)->left) {
                    node = node->parent;
                    rb_rotate_right(tree, node);
                }
                (node->parent)->color = 0;
                ((node->parent)->parent)->color = 1;
                rb_rotate_left(tree, (node->parent)->parent);
            }
        }
    }

    (tree->root)->color = 0;
}

void insertion(rbtree* tree, rbnode* node)
{
    rbnode* parent = tree->NIL;
    rbnode* tmp = tree->root;

    while (tmp != tree->NIL)
    {
        parent = tmp;
        if (node->data < tmp->data)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    node->parent = parent;

    if (parent == tree->NIL)
        tree->root = node;
    else if (node->data < parent->data)
        parent->left = node;
    else
        parent->right = node;

    node->left = tree->NIL;
    node->right = tree->NIL;
    node->color = 1;

    rb_check_rule(tree, node);
}

void inorder(rbtree* tree, rbnode* node)
{
    if (node != tree->NIL) {
        inorder(tree, node->left);
        printf("%d %s\n", node->data, node->color == 1 ? "RED" : "BLACK");
        inorder(tree, node->right);
    }
}

void preorder(rbtree* tree, rbnode* node)
{
    if (node != tree->NIL) {
        printf("%d %s\n", node->data, node->color == 1 ? "RED" : "BLACK");
        preorder(tree, node->left);
        preorder(tree, node->right);
    }
}

void postorder(rbtree* tree, rbnode* node)
{
    if (node != tree->NIL) {
        postorder(tree, node->left);
        postorder(tree, node->right);
        printf("%d %s\n", node->data, node->color == 1 ? "RED" : "BLACK");
    }
}

int main()
{
    rbtree* tree = make_tree();

    insertion(tree, make_node(41));
    insertion(tree, make_node(38));
    insertion(tree, make_node(31));
    insertion(tree, make_node(12));
    insertion(tree, make_node(19));
    insertion(tree, make_node(8));

    printf("Inorder Traversal\n");
    inorder(tree, tree->root);
    printf("\n");
    printf("Preorder Traversal\n");
    preorder(tree, tree->root);
    printf("\n");
    printf("Postorder Traversal\n");
    postorder(tree, tree->root);
    printf("\n");

    return 0;
}
