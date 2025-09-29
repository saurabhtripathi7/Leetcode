class Solution {
public:
    
    int solve(int n, vector<int>&costs,int i,vector<int>&dp){
        if(i>n)
        return INT_MAX;
        if(i==n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];
        int ans = INT_MAX;
        for(int step =1;step<=3;step++){
            int j = i+step;
            if(j<=n){
                int cost = costs[j-1] + step*step;               
                int recr = solve(n,costs,j,dp);
                if(recr!=INT_MAX){
                    ans = min(ans,cost+recr);
                }
            }
        }
        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(n,costs,0,dp);
    }
};
