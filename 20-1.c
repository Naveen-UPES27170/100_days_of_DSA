#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    if (*(long long*)a < *(long long*)b) return -1;
    if (*(long long*)a > *(long long*)b) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    long long *prefix_sums = (long long *)malloc((n + 1) * sizeof(long long));
    
    prefix_sums[0] = 0; // Base case: prefix sum before any elements is 0
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        current_sum += arr[i];
        prefix_sums[i + 1] = current_sum;
    }

    // Sort prefix sums to find duplicates easily
    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long frequency = 1;

    // If a prefix sum appears 'k' times, it contributes kC2 pairs
    // Formula: k * (k - 1) / 2
    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            frequency++;
        } else {
            count += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    // Add the last group
    count += (frequency * (frequency - 1)) / 2;

    printf("%lld\n", count);

    free(arr);
    free(prefix_sums);
    return 0;
}