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
        vector<vector<bool>>dp(n+1, vector<bool>(target+1, false)); // n+1 bcz of base case check at i == n

        dp[n][target] = true;

        for(int i = n-1; i >= 0; --i){
            for(int currSum = 0; currSum <= target; ++currSum){
                int skip = dp[i+1][currSum];
                int pick = false;
                if(currSum + nums[i] <= target) 
                    pick = dp[i+1][currSum + nums[i]];
                dp[i][currSum] = skip || pick;
            }
        }

        return dp[0][0];  
    }
};