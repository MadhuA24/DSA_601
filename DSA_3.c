//Network Routing System

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, i, x, newID;
    struct Node* root = NULL;

    if (scanf("%d", &n) != 1 || n == -1 || n < 1 || n > 100) {
        printf("Invalid input");
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (scanf("%d", &x) != 1 || x == -1) {
            printf("Invalid input");
            return 0;
        }
        root = insert(root, x);
    }

    if (scanf("%d", &newID) != 1 || newID == -1) {
        printf("Invalid input");
        return 0;
    }

    root = insert(root, newID);

    inorder(root);

    return 0;
}
