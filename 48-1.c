#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to count leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    // If current node is a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    // Otherwise, sum the leaves from both subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// Standard Level-Order construction for input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

int main() {
    int n;
    // Input: Size of array representing level-order traversal
    if (scanf("%d", &n) != 1) return 0;

    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    // Output the leaf count
    printf("%d\n", countLeaves(root));

    return 0;
}
