class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(j < 0 || j >= m) return INT_MAX;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = matrix[i][j] + solve(i+1, j, n, m, dp, matrix);
        int diag1 = j-1 >= 0 ? matrix[i][j] + solve(i+1, j-1, n, m, dp, matrix) : INT_MAX;
        int diag2 = j+1 < m ? matrix[i][j] + solve(i+1, j+1, n, m, dp, matrix) : INT_MAX;

        return dp[i][j] = min({down, diag1, diag2});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;

        for(int j = 0; j < m; j++) {
            ans = min(ans, solve(0, j, n, m, dp, matrix));
        }
        return ans;
    }
};

