#include <stdio.h>
#include <stdbool.h>

// Function to check if it's possible to allocate books with a max limit of 'mid'
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book is larger than our limit, it's impossible
        if (arr[i] > mid) return false;

        if (currentSum + arr[i] > mid) {
            // Assign to the next student
            studentCount++;
            currentSum = arr[i];
            
            if (studentCount > m) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    // If books are fewer than students, allocation is impossible 
    // (given the constraint that each student must get at least one book)
    if (n < m) return -1;

    int sum = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal, high = sum;
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;    // This capacity works, try to minimize further
            high = mid - 1;
        } else {
            low = mid + 1;   // Need more capacity per student
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", findPages(arr, n, m));

    return 0;
}
