#include <stdio.h>

// Lower Bound: First element >= x
int findLowerBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            high = mid; // Look on the left side
        } else {
            low = mid + 1; // Look on the right side
        }
    }
    return low;
}

// Upper Bound: First element > x
int findUpperBound(int arr[], int n, int x) {
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            high = mid; // Look on the left side
        } else {
            low = mid + 1; // Look on the right side
        }
    }
    return low;
}

int main() {
    int n, x;
    
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d", &x) != 1) return 0;

    int lb = findLowerBound(arr, n, x);
    int ub = findUpperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}
