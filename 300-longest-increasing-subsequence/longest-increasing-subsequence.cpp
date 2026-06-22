class Solution {
public:
    int n;
    int solve(int idx, int prev, vector<vector<int>>& dp, vector<int>& nums){
        if(idx == n) return 0;

        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int skip = solve(idx+1, prev, dp, nums);
        int pick = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            pick = 1 + solve(idx+1, idx, dp, nums);
        }
        return dp[idx][prev+1] = max(pick, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solve(0, -1, dp, nums);
    }
};