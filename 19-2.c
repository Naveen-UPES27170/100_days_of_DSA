#include <math.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int totalSum = 0;
    int currentMax = 0, maxSum = nums[0];
    int currentMin = 0, minSum = nums[0];

    for (int i = 0; i < numsSize; i++) {
        // 1. Standard Kadane for Maximum Subarray
        currentMax = (nums[i] > currentMax + nums[i]) ? nums[i] : currentMax + nums[i];
        if (currentMax > maxSum) maxSum = currentMax;

        // 2. Standard Kadane for Minimum Subarray
        currentMin = (nums[i] < currentMin + nums[i]) ? nums[i] : currentMin + nums[i];
        if (currentMin < minSum) minSum = currentMin;

        totalSum += nums[i];
    }

    /* If maxSum is negative, it means all numbers in the array are negative.
       In this case, totalSum - minSum would be 0 (the sum of an empty subarray),
       which isn't allowed. We must return the largest single element (maxSum).
    */
    if (maxSum < 0) {
        return maxSum;
    }

    // Return the better of the linear max or the circular max
    int circularMax = totalSum - minSum;
    return (maxSum > circularMax) ? maxSum : circularMax;
}