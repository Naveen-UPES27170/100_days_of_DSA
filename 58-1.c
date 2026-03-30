#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Search function to find index of root in inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Core function to build the tree
struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* node = newNode(preorder[(*preIndex)++]);

    // If this node has no children, return
    if (inStart == inEnd) return node;

    // Else find the index of this node in Inorder traversal
    int inIndex = search(inorder, inStart, inEnd, node->data);

    // Using index in Inorder traversal, construct left and right subtrees
    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* preorder = malloc(n * sizeof(int));
    int* inorder = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);
    printf("\n");

    return 0;
}
