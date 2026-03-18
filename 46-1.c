#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Level Order Traversal function
void levelOrder(struct Node* root, int n) {
    if (root == NULL) return;

    // Create a queue for nodes
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;

    // Enqueue root
    queue[tail++] = root;

    while (head < tail) {
        // Dequeue
        struct Node* current = queue[head++];
        printf("%d ", current->data);

        // Enqueue left child
        if (current->left != NULL) {
            queue[tail++] = current->left;
        }

        // Enqueue right child
        if (current->right != NULL) {
            queue[tail++] = current->right;
        }
    }
    free(queue);
}

// Construction from Level-Order (Standard for these problems)
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
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    levelOrder(root, n);
    printf("\n");

    return 0;
}
