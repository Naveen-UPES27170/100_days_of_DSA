#include <stdio.h>

// Function to find the maximum length of a subarray with sum 0
int maxLen(int arr[], int n) {
    int max_l = 0;
    int curr_sum = 0;

    // In a production scenario, use a Hash Map to store (sum, index)
    // For simplicity in C, we simulate the logic:
    for (int i = 0; i < n; i++) {
        curr_sum = 0;
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];

            if (curr_sum == 0) {
                int length = j - i + 1;
                if (length > max_l) {
                    max_l = length;
                }
            }
        }
    }
    return max_l;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}
