class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        long long maxSum = LLONG_MIN;

        // Initialize the min_prefix array with LLONG_MAX, except min_prefix[0] = 0
        vector<long long> min_prefix(k, LLONG_MAX);
        min_prefix[0] = 0; // For subarrays starting from index 0

        long long prefixSum = 0;
        
        // Iterate over the array to compute prefix sums
        for (int j = 1; j <= n; ++j) {
            prefixSum += nums[j - 1];
            
            int r = j % k; // remainder when dividing by k
            
            // Check if a valid subarray exists with a length divisible by k
            if (min_prefix[r] != LLONG_MAX) {
                long long currSum = prefixSum - min_prefix[r];
                maxSum = max(maxSum, currSum);
            }
            
            // Update the minimum prefix sum for this remainder
            min_prefix[r] = min(min_prefix[r], prefixSum);
        }

        return maxSum == LLONG_MIN ? -1 : maxSum;
    }
};

