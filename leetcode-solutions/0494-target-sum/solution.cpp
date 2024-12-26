class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;

        // If (S + target) is odd or target is not achievable, return 0
        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;

        int subsetSum = (sum + target) / 2;

        // DP array to store the number of ways to achieve a sum
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0 (choose no elements)

        // Fill DP table
        for (int num : nums) {
            for (int j = subsetSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subsetSum];
    }
};

