class Solution {
public:
    int n;
    
    int solve(int i, int prevCol, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == n) return 0;

        if (dp[i][prevCol + 1] != INT_MAX) return dp[i][prevCol + 1];

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (j != prevCol) {
                ans = min(ans, grid[i][j] + solve(i + 1, j, grid, dp));
            }
        }

        return dp[i][prevCol + 1] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        // prevCol can range from -1 to n-1, so we store in dp[n][n+1]
        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX));

        return solve(0, -1, grid, dp);
    }
};
