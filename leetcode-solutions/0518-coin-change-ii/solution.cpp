class Solution {
public:
    int n;
    int solve(int i, int amt, vector<int>& coins, vector<vector<int>>&dp){
        if(amt == 0) return 1;
        if(i >= n || amt < 0) return 0;
        if(dp[i][amt] != -1) return dp[i][amt];

        int skip = solve(i+1, amt, coins, dp);
        int pick = 0;
        if(coins[i] <= amt){
            pick = solve(i, amt - coins[i], coins, dp);
        }
        return dp[i][amt] = pick+skip;

    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};
