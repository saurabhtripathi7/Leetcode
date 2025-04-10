class Solution {
public:
    int solve(int i, int amt, vector<int>& coins, int n, vector<vector<int>>&dp) {
        if (amt == 0) return 0;                // Base case: exact amount formed
        if (amt < 0 || i >= n) return 1e9;     // Invalid: return max value
        if(dp[i][amt] != -1) return dp[i][amt];

        // Option 1: pick the coin at index i (stay at i, because we can reuse it)
        int pick = 1 + solve(i, amt - coins[i], coins, n, dp);

        // Option 2: don't pick the coin at i, move to next index
        int notPick = solve(i + 1, amt, coins, n, dp);

        return dp[i][amt] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int res = solve(0, amount, coins, n, dp);
        return res == 1e9 ? -1 : res;
    }
};

