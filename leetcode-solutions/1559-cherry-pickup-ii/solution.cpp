class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();      // rows
        int m = grid[0].size();   // columns

        // dp[row][col1][col2] -> max cherries collected from row `row`
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        // Base case: fill for the last row
        for (int j1 = 0; j1 < m; ++j1) {
            for (int j2 = 0; j2 < m; ++j2) {
                if (j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Bottom-up calculation
        for (int i = n - 2; i >= 0; --i) {
            for (int j1 = 0; j1 < m; ++j1) {
                for (int j2 = 0; j2 < m; ++j2) {
                    int maxCherries = INT_MIN;

                    for (int dj1 = -1; dj1 <= 1; ++dj1) {
                        for (int dj2 = -1; dj2 <= 1; ++dj2) {
                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                                int val = dp[i+1][nj1][nj2];
                                if (j1 == j2) val += grid[i][j1];
                                else val += grid[i][j1] + grid[i][j2];
                                maxCherries = max(maxCherries, val);
                            }
                        }
                    }

                    dp[i][j1][j2] = maxCherries;
                }
            }
        }

        // Initial positions: (0, 0) and (0, m - 1)
        return dp[0][0][m - 1];
    }
};

