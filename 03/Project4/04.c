#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
}node;

void setting(node* tree) {
    tree->data = 6;
    node* left = malloc(sizeof(node));
    tree->left = left;
    node* right = malloc(sizeof(node));
    tree->right = right;

    left->data = 2;
    node* ll, * lr;
    ll = malloc(sizeof(node));
    lr = malloc(sizeof(node));
    left->left = ll;
    left->right = lr;
    ll->data = 1;
    ll->left = ll->right = NULL;
    lr->data = 3;
    lr->left = lr->right = NULL;

    right->data = 8;
    node* rl, * rr;
    rl = malloc(sizeof(node));
    rr = malloc(sizeof(node));
    right->left = rl;
    right->right = rr;
    rl->data = 7;
    rl->left = rl->right = NULL;
    rr->data = 9;
    rr->left = rr->right = NULL;
}

int find_lca(node* root, int a, int b) {
    if (root->data > a && root->data < b)
        return root->data;
    else if (root->data == a || root->data == b)
        return root->data;
    else if (root->data > b) {
        return find_lca(root->left, a, b);
    }
    else return find_lca(root->right, a, b);
}

int main() {
    node* root = malloc(sizeof(node));
    setting(root);

    int a, b;

    scanf("%d %d", &a, &b);

    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    printf("%d is the lowest common ancestor.", find_lca(root, a, b));

    return 0;
}