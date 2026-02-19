#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestPair(int arr[], int n) {
    if (n < 2) return;

    // 1. Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = INT_MAX;
    int res_l = left, res_r = right;

    // 2. Two-pointer approach
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update minimum sum if we found a "closer" one
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        // Move pointers based on sum
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("The two elements whose sum is closest to zero are %d and %d\n", arr[res_l], arr[res_r]);
    printf("Their sum is: %d\n", min_sum);
}

int main() {
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findClosestPair(arr, n);
    return 0;
}