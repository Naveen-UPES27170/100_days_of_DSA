#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Global or passed variable to track the maximum level visited so far
int max_level = -1;

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive function for Right View
void rightView(struct Node* root, int level) {
    if (root == NULL) return;

    // If this is the first time we've reached this level, it's the rightmost node
    if (level > max_level) {
        printf("%d ", root->data);
        max_level = level;
    }

    // Traverse Right first, then Left
    rightView(root->right, level + 1);
    rightView(root->left, level + 1);
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
    
    rightView(root, 0);
    printf("\n");

    return 0;
}
