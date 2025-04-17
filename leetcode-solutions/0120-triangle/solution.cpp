class Solution {
public:
    int solve(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == n - 1)
            return triangle[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int adj1 = triangle[i][j] + solve(i + 1, j, n, triangle, dp);
        int adj2 = triangle[i][j] + solve(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = min(adj1, adj2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(triangle[i].size(), INT_MAX);
        }

        return solve(0, 0, n, triangle, dp);
    }
};
