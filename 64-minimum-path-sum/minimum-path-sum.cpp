class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // dp[x][y] = min sum to reach x,y from 0,0
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        // init with Running sum of 1st row and col
        for(int j = 1; j < n; ++j) dp[0][j] = grid[0][j] + dp[0][j-1]; 
        for(int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i-1][0];

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                int left = dp[i][j-1];
                int up = dp[i-1][j];
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
        return dp[m-1][n-1];
    }
};