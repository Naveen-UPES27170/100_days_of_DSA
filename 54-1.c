#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;

    // Two stacks for alternating levels
    struct Node** s1 = malloc(n * sizeof(struct Node*));
    struct Node** s2 = malloc(n * sizeof(struct Node*));
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        // Left to Right
        while (top1 >= 0) {
            struct Node* curr = s1[top1--];
            printf("%d ", curr->data);

            if (curr->left) s2[++top2] = curr->left;
            if (curr->right) s2[++top2] = curr->right;
        }

        // Right to Left
        while (top2 >= 0) {
            struct Node* curr = s2[top2--];
            printf("%d ", curr->data);

            if (curr->right) s1[++top1] = curr->right;
            if (curr->left) s1[++top1] = curr->left;
        }
    }
    free(s1);
    free(s2);
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
    zigzagTraversal(root, n);
    printf("\n");

    return 0;
}
