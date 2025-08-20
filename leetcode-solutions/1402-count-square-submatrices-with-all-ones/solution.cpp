class Solution {
public:
    int n, m;
    // int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
    //     if(i >= n || i < 0 || j >= m || j < 0) return 0;
    //     if(matrix[i][j] == 0) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int right = solve(i, j+1, matrix, dp);
    //     int left = solve(i+1, j, matrix, dp);
    //     int diag = solve(i+1, j+1, matrix, dp);

    //     return dp[i][j] = 1 + min({right, left, diag});
    // }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i = n-1; i >= 0; --i){
            for(int j = m-1; j >= 0; --j){
                if(matrix[i][j] == 1)
                {
                    if(i == n-1 || j == m-1) {
                        dp[i][j] = 1; // bottom row or rightmost col
                    } else {
                        dp[i][j] = 1 + min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
