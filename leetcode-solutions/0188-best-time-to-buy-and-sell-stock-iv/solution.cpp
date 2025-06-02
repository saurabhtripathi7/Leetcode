class Solution {
public:
    int n;
    int solve(int ind, int state, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == n || cap == 0) return 0;
        if (dp[ind][state][cap] != -1) return dp[ind][state][cap];

        int profit = 0;

        if (state) { // can buy
            int buyToday = -prices[ind] + solve(ind + 1, 0, cap, prices, dp);
            int skipToday = 0 + solve(ind + 1, 1, cap, prices, dp);
            profit = max(buyToday, skipToday);
        } else { // can sell
            int sellToday = prices[ind] + solve(ind + 1, 1, cap-1, prices, dp);
            int skipToday = 0 + solve(ind + 1, 0, cap, prices, dp);
            profit = max(sellToday, skipToday);
        }

        return dp[ind][state][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        // dp[n][2][3] -> ind(0....n-1), state(0,1), maxCap (0,1,2..k)
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};
