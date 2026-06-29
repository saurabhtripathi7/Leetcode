class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0)); // no of ways to reach ith, jth cell

        for(int i = 0; i < n; ++i) dp[0][i] = 1; // 1st col only 1 way D->D...
        for(int i = 0; i < m; ++i) dp[i][0] = 1; // 1st row only 1 way R->R...

        for(int i = 1; i < m; ++i){
            cout<<" i:"<<i;
            for(int j = 1; j < n; ++j){
                int up = dp[i-1][j];
                int left = dp[i][j-1];
                dp[i][j] = up + left;
                cout<<" up: "<<up<<" left: "<<left<<" curr: "<<dp[i][j];
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};