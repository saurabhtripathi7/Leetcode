const long long MOD = 1e18;  // pick a safe big MOD to avoid overflow

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int amt = 0; amt <= amount; ++amt) {
                long long skip = dp[i + 1][amt];
                long long pick = 0;
                if (coins[i] <= amt) {
                    pick = dp[i][amt - coins[i]];
                }
                dp[i][amt] = (pick + skip) % MOD;
            }
        }
        return dp[0][amount];
    }
};

