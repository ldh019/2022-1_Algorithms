#include <stdio.h>

typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
}node;

int get_min(node* root) {
    while (root->left)
        root = root->left;
    return root->data;
}
int get_max(node* root) {
    while (root->right)
        root = root->right;
    return root->data;
}
int is_bst(node* root) {
    if (!root)
        return 1;

    if (root->left && get_max(root->left) > root->data)
        return 0;

    if (root->right && get_min(root->right) < root->data)
        return 0;

    if (!is_bst(root->left) || !is_bst(root->right))
        return 0;

    return 1;
}

void setting(node* tree) {
    tree->data = 8;
    node* left = malloc(sizeof(node));
    tree->left = left;
    node* right = malloc(sizeof(node));
    tree->right = right;
    left->data = 3;
    left->left = left->right = NULL;
    right->data = 9;

    node* rl,* rr;
    rl = malloc(sizeof(node));
    rr = malloc(sizeof(node));
    right->left = rl;
    right->right = rr;
    rl->data = 4;
    rl->left = rl->right = NULL;
    rr->data = 7;
    rr->left = rr->right = NULL;
}

int main() {
    node* root = malloc(sizeof(node));
    setting(root);

    if (is_bst(root)) printf("It is a valid binary search tree.");
    else printf("It is not a valid binary search tree.");

    return 0;
}