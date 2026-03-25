#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Queue element to store node and its horizontal distance
struct QueueItem {
    struct Node* node;
    int hd;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to find the range of horizontal distances
void findMinMax(struct Node* node, int* min, int* max, int hd) {
    if (node == NULL) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// Function to print a specific vertical line
void printVerticalLine(struct Node* root, int line_no, int hd) {
    if (root == NULL) return;

    // Use a queue to ensure top-to-bottom order (Level Order style)
    struct QueueItem queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = (struct QueueItem){root, 0};

    int first = 1;
    while (head < tail) {
        struct QueueItem curr = queue[head++];
        if (curr.hd == line_no) {
            if (!first) printf(" ");
            printf("%d", curr.node->data);
            first = 0;
        }
        if (curr.node->left) queue[tail++] = (struct QueueItem){curr.node->left, curr.hd - 1};
        if (curr.node->right) queue[tail++] = (struct QueueItem){curr.node->right, curr.hd + 1};
    }
}

void verticalOrder(struct Node* root, int n) {
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // For every vertical line from leftmost to rightmost
    for (int line = min; line <= max; line++) {
        printVerticalLine(root, line, 0);
        printf("\n");
    }
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
    verticalOrder(root, n);

    return 0;
}
