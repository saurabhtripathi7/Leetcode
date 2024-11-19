class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans; // If k is 0, all results are 0.

        int sum = 0;
        int start = 1, end = 0;

        if (k > 0) { // If k > 0, calculate the sum of the first k elements to the right of nums[0].
            for (end = 1; end <= k; ++end) {
                sum += nums[end % n];
            }
        } else { // If k < 0, calculate the sum of the |k| elements to the left of nums[0].
            for (end = n + k; end < n; ++end) {
                sum += nums[end % n];
            }
            start = n + k;
        }

        // Sliding window for all elements
        for (int i = 0; i < n; ++i) {
            ans[i] = sum;

            // Slide the window
            sum -= nums[start % n];
            start++;
            sum += nums[end % n];
            end++;
        }

        return ans;
    }
};

