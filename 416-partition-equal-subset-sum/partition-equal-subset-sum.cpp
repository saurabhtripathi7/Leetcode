class Solution {
public:
    bool solve(int i, int currSum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (currSum > target) return false;

        if (i == nums.size()) {
            return currSum == target;
        }

        if (dp[i][currSum] != -1)
            return dp[i][currSum];

        bool skip = solve(i + 1, currSum, nums, target, dp);
        bool pick = solve(i + 1, currSum + nums[i], nums, target, dp);

        return dp[i][currSum] = skip || pick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total & 1) return false;

        int target = total/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1)); // true, false and -1 for unvis state
        return solve(0, 0, nums, target, dp);  
    }
};