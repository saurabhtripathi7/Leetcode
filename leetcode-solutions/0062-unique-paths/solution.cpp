class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>&dp) {
        if(i >= m || j >= n) return 0;                                    // reached out of bounds - invalid
        if(i == m-1 && j == n-1) return 1;                                // reached the destination - valid solution
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp);     // try both down and right
    }

    int uniquePaths(int m, int n, int i = 0, int j = 0) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        if(m == 1 & n == 1) return 1;
        return solve(m, n, i+1, j, dp) + solve(m, n, i, j+1, dp);     // try both down and right
    }
};
