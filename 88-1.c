#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with at least 'dist' distance
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // Place the first cow in the first stall
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= dist) {
            count++;
            last_pos = stalls[i]; // Update position of the last placed cow
            if (count >= k) return 1; // Successfully placed all cows
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stall positions
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search on the distance
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;   // This distance works, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Distance too large, shrink the limit
        }
    }

    printf("%d\n", result);

    return 0;
}
