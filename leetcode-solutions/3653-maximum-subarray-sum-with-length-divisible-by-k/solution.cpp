class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long maxSum = LLONG_MIN; // Initialize maxSum to the smallest possible value

        // Initialize the min_prefix array to track the minimum prefix sum for each remainder when dividing by k.
        // Use LLONG_MAX as a placeholder for "unreachable" states. Set min_prefix[0] = 0 for subarrays starting at index 0.
        vector<long long> min_prefix(k, LLONG_MAX);
        min_prefix[0] = 0; // A subarray starting at index 0 has a prefix sum of 0.

        long long prefixSum = 0; // Variable to store the cumulative sum (prefix sum).

        // Iterate through the array to calculate prefix sums and check for valid subarrays.
        for (int j = 1; j <= n; ++j) {
            prefixSum += nums[j - 1]; // Update the prefix sum to include the current element.

            int r = j % k; // Calculate the remainder when the current index is divided by k.

            // If there exists a valid subarray whose length is divisible by k,
            // the condition min_prefix[r] != LLONG_MAX ensures that a prefix sum
            // with this remainder has been encountered previously.
            if (min_prefix[r] != LLONG_MAX) {
                long long currSum = prefixSum - min_prefix[r]; // Compute the sum of the subarray.
                maxSum = max(maxSum, currSum); // Update maxSum if the current subarray sum is larger.
            }

            // Update the minimum prefix sum for the current remainder.
            // This ensures that future subarrays can use the smallest prefix sum for their calculations.
            min_prefix[r] = min(min_prefix[r], prefixSum);
        }

        // If maxSum remains unchanged (no valid subarray was found), return -1.
        // Otherwise, return the maximum subarray sum found.
        return maxSum == LLONG_MIN ? -1 : maxSum;
    }
};

