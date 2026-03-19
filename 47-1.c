#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
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

// Recursive function to find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursively find the height of left and right subtrees
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Height of current node is 1 + max(leftHeight, rightHeight)
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Function to build a tree from level-order input array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    
    queue[tail++] = root;
    int i = 1;

    while (i < n) {
        struct Node* current = queue[head++];
        
        // Left child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }
        
        // Right child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

int main() {
    int n;
    // Input: Number of elements in level-order traversal
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    
    // Output the result
    printf("%d\n", findHeight(root));

    return 0;
}
