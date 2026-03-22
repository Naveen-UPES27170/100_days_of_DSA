#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Standard BST Insert to set up the tree
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// BST Search Function
struct Node* search(struct Node* root, int key) {
    // Base Case: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's data
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's data
    return search(root->left, key);
}

int main() {
    struct Node* root = NULL;
    int n, val, key;

    // Input: Number of elements to insert
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input: Key to search for
    scanf("%d", &key);

    struct Node* result = search(root, key);

    if (result != NULL)
        printf("Present\n");
    else
        printf("Not Present\n");

    return 0;
}
