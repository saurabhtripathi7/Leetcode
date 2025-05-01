class Solution {
public:
    // int solve(int i, int amt, vector<int>& coins, int n,
    // vector<vector<int>>&dp) {
    //     if (amt == 0) return 0;                // Base case: exact amount
    //     formed if (amt < 0 || i >= n) return 1e9;     // Invalid: return max
    //     value

    //     if(dp[i][amt] != -1) return dp[i][amt];

    //     // Option 1: pick the coin at index i (stay at i, because we can
    //     reuse it) int pick = 1 + solve(i, amt - coins[i], coins, n, dp);

    //     // Option 2: don't pick the coin at i, move to next index
    //     int notPick = solve(i + 1, amt, coins, n, dp);

    //     return dp[i][amt] = min(pick, notPick);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    //     int res = solve(0, amount, coins, n, dp);
    //     return res == 1e9 ? -1 : res;
    // }

    // TABULATION
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        // Base case: 0 coins to make amount 0
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; --i) { //from n-1 to 0, bcz at the end we want to return dp[0][amount]
            for (int amt = 1; amt <= amount; ++amt) {
                // Not pick
                int notPick = dp[i + 1][amt];

                // Pick
                int pick = 1e9;
                if (coins[i] <= amt) {
                    pick = 1 + dp[i][amt - coins[i]];
                }

                dp[i][amt] = min(pick, notPick);
            }
        }

        int ans = dp[0][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};

