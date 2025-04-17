class Solution {
public:
    int solve(int i, int curr, int n, vector<int>& squares, vector<vector<int>>& dp) {
        if (curr > n) return INT_MAX;
        if (curr == n) return 0;
        if (i >= squares.size()) return INT_MAX;

        if (dp[i][curr] != -1) return dp[i][curr];

        int pickRes = solve(i, curr + squares[i], n, squares, dp);
        int pick = (pickRes == INT_MAX) ? INT_MAX : 1 + pickRes;

        int notPick = solve(i + 1, curr, n, squares, dp);

        return dp[i][curr] = min(pick, notPick);
    }

    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; ++i) {
            squares.push_back(i * i);
        }

        vector<vector<int>> dp(squares.size(), vector<int>(n + 1, -1));
        return solve(0, 0, n, squares, dp);
    }
};

