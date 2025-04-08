class Solution {
public:
        int solve(vector<int>& nums, int size, int index, vector<int>&dp) {
        //base case
        if(index >= size ) {
            return 0;
        }
        if(dp[index] != -1) return dp[index];

        //rob the ith house and dont go to adj house (pick)
        int option1 = nums[index] + solve(nums, size, index+2, dp);

        //dont rob ith curr house but go for adj house (not pick)
        int option2 = 0 + solve(nums, size, index+1, dp);

        return dp[index] = max(option1, option2);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        vector<int>dp(size+1, -1);
        return solve(nums, size, index, dp);
    }
};
