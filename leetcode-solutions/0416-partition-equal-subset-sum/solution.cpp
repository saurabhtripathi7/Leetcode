class Solution {
public:
    bool solve(int i, int currSum, vector<int>& nums, int &target, vector<vector<int>>&dp){
        if(i >= nums.size() || currSum > target) return false;
        if(currSum == target) return true;
        
        if(dp[i][currSum] != -1) return dp[i][currSum];

        bool include = solve(i+1, currSum + nums[i], nums, target, dp);
        bool exclude = solve(i+1, currSum, nums, target, dp);

        return dp[i][currSum] =include || exclude; 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total/2;
        if(total & 1) return false;

        //rows(i) : 0 -> n
        // cols(currSum) : 0 -> target+1 
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        return solve(0, 0, nums, target, dp);    
    }
};
