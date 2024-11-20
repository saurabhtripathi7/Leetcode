class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int l = 0, r = 0;  // Sliding window pointers
        unordered_map<int, int> mpp;  // Frequency map
        long long sum = 0, maxSum = 0;  // Sum and max sum

        // Initialize the first window of size `k`
        for (r = 0; r < k; r++) {
            mpp[arr[r]]++;  // Track element frequency
            sum += arr[r];   // Update sum
        }

        // Sliding window
        while (r < arr.size()) {
            if (mpp.size() == k) {
                maxSum = max(maxSum, sum);  // Update max sum for valid window
            }

            // Shrink window from left
            sum -= arr[l];
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;

            // Expand window to right
            mpp[arr[r]]++;
            sum += arr[r];
            r++;
        }

        // Check last window
        if (mpp.size() == k) {
            maxSum = max(maxSum, sum);  // Update max sum
        }

        return maxSum;  // Return result
    }
};

