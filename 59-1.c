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

// Search for index of root in inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Core function to build the tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    // Base case
    if (inStart > inEnd) return NULL;

    // Pick current node from Postorder traversal using postIndex (moving backwards)
    struct Node* node = newNode(postorder[(*postIndex)--]);

    // If this node has no children, return
    if (inStart == inEnd) return node;

    // Find the index of this node in Inorder traversal
    int inIndex = search(inorder, inStart, inEnd, node->data);

    /* IMPORTANT: In Postorder (LRN), the root is at the end. 
       Moving backward from the end, we encounter: Root -> Right -> Left.
       So, we MUST build the Right subtree first.
    */
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Preorder Traversal: Root -> Left -> Right
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* inorder = malloc(n * sizeof(int));
    int* postorder = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    // Start postIndex from the last element
    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorderTraversal(root);
    printf("\n");

    return 0;
}
