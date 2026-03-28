#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to check if two subtrees are mirrors
bool isMirror(struct Node* t1, struct Node* t2) {
    // If both are NULL, they are mirrors
    if (t1 == NULL && t2 == NULL) return true;
    
    // If only one is NULL, or data doesn't match, not mirrors
    if (t1 == NULL || t2 == NULL) return false;
    if (t1->data != t2->data) return false;

    // Check inner and outer pairs
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct Node* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}

// Standard Level-Order construction
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** q = malloc(n * sizeof(struct Node*));
    int h = 0, t = 0;
    q[t++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[h++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) q[t++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) q[t++] = curr->right;
        }
    }
    free(q);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    
    if (isSymmetric(root)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
