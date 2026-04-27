#include <stdio.h>

long long integerSquareRoot(long long n) {
    if (n < 2) return n;

    long long low = 0, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        // Check if mid*mid is less than or equal to n
        // Using division (n / mid) helps prevent integer overflow
        if (mid <= n / mid) {
            ans = mid;     // Store mid as a potential answer
            low = mid + 1; // Try for a larger value
        } else {
            high = mid - 1; // mid is too large
        }
    }
    return ans;
}

int main() {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;

    if (n < 0) {
        // Square root of negative numbers is not defined in real integers
        return 0;
    }

    printf("%lld\n", integerSquareRoot(n));

    return 0;
}
