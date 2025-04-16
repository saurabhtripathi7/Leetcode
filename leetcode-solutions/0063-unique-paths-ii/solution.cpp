class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m = grid.size(), n = grid[0].size();
        
        // If start or end is blocked, return 0
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // Initialize starting point
        dp[0][0] = 1;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                // Skip if cell is blocked
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                // Add paths from top
                if (i > 0) dp[i][j] += dp[i - 1][j];

                // Add paths from left
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};
