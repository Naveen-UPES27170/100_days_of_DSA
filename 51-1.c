#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new BST node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Standard BST Insert
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Function to find the LCA in a BST
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        // If both p and q are smaller than root, LCA is in left
        if (p < root->data && q < root->data)
            root = root->left;
        
        // If both p and q are greater than root, LCA is in right
        else if (p > root->data && q > root->data)
            root = root->right;
        
        // We have found the split point
        else
            break;
    }
    return root;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input number of nodes
    if (scanf("%d", &n) != 1) return 0;

    // Build the BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input the two nodes to find LCA for
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}
