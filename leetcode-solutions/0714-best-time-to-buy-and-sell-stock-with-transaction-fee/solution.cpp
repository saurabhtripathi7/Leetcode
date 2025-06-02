class Solution {
public:
    int n;
    int fee;
    int solve(int ind, int state, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == n) return 0;
        if (dp[ind][state] != -1) return dp[ind][state];

        int profit = 0;

        if (state) { // can buy
            int buyToday = -prices[ind] + solve(ind + 1, 0, prices, dp);
            int skipToday = 0 + solve(ind + 1, 1, prices, dp);
            profit = max(buyToday, skipToday);
        } else { // can sell
            int sellToday = prices[ind] -fee + solve(ind + 1, 1, prices, dp);
            int skipToday = 0 + solve(ind + 1, 0, prices, dp);
            profit = max(sellToday, skipToday);
        }

        return dp[ind][state] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        this->fee = fee;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
