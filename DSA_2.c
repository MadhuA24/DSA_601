//Desktop File Indexing System
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: no child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (no trailing space)
void inorder(struct Node* root, int *first) {
    if (root == NULL)
        return;

    inorder(root->left, first);

    if (*first) {
        printf("%d", root->data);
        *first = 0;
    } else {
        printf(" %d", root->data);
    }

    inorder(root->right, first);
}

int main() {
    int n, val, del;
    struct Node* root = NULL;

    // Read number of nodes
    scanf("%d", &n);

    // Insert initial nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Insert one more node
    scanf("%d", &val);
    root = insert(root, val);

    // Delete a node
    scanf("%d", &del);
    root = deleteNode(root, del);

    // Print result
    printf("Current File Index sorted in ascending order: ");

    int first = 1;
    inorder(root, &first);

    printf("\n");

    return 0;
}
