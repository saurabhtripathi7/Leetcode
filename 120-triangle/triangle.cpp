class Solution {
public: 
    int n;
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i >= n || j >= grid[i].size()) return 1e9;
        if(i == n-1) return grid[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int first = solve(i+1, j, dp, grid);
        int second = solve(i+1, j+1, dp, grid);

        return dp[i][j] = grid[i][j] + min(first, second);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX)); // -1 is a valid state, so cant take it
        return solve(0, 0, dp, triangle);
    }
};