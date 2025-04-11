class Solution {
public:
    int solve(vector<int>& nums, int s, int e, vector<int>&dp){
        // base case
        if(s > e) return 0;
        if(dp[s] != -1) return dp[s];

        // include
        int ans1 = nums[s] + solve(nums, s+2, e, dp);
        // exclude
        int ans2 = 0 + solve(nums, s+1, e, dp);

        int ans = max(ans1, ans2);
        return dp[s] = ans;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
                
        if(n == 1) return nums[0];
        // missed single element case here 

        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        
        int ans1 = solve(nums, 0, n-2, dp1); //including first 
        int ans2 = solve(nums, 1, n-1, dp2); //includind second

        return max(ans1,ans2);
    }
}; 
