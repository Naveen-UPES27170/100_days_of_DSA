#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if the array represents a Min-Heap
bool isMinHeap(int arr[], int n) {
    // Start from the first node and go up to the last internal node
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // Check if left child exists and violates the min-heap property
        int leftChild = 2 * i + 1;
        if (leftChild < n && arr[i] > arr[leftChild]) {
            return false;
        }

        // Check if right child exists and violates the min-heap property
        int rightChild = 2 * i + 2;
        if (rightChild < n && arr[i] > arr[rightChild]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    
    // Input: Number of elements
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        // Read level-order traversal
        // Note: Use -1 or a specific value if your input handles NULLs, 
        // but standard heap checks assume a complete tree.
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(arr);
    return 0;
}
