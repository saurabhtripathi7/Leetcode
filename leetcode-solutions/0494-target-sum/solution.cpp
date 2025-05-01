class Solution {
public:
    int n, offset;
    int solve(int i, int sum, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= n) return target == sum;
        if(dp[i][sum + offset] != -1) return dp[i][sum + offset];

        int pos = solve(i+1, sum + nums[i], target, nums, dp);
        int neg = solve(i+1, sum - nums[i], target, nums, dp);
        
        return dp[i][sum + offset] = pos + neg;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        offset = maxSum; // in order to avoid negative indices for sum
        //sum can range from [-maxSum, +maxSum]
        // Offset is used to handle negative sums by shifting the range [-maxSum, +maxSum] to [0, 2*maxSum]
        // This allows us to store all possible sums as valid non-negative indices in the DP table
        offset = maxSum;

        vector<vector<int>>dp(n, vector<int>(2*maxSum+1 , -1));
        
        return solve(0, 0, target, nums, dp);
    }
};
