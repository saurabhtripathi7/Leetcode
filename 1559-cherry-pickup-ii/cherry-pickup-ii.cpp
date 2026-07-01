class Solution {
public:
    int m, n;
    int solve(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        if(j1 >= n || j2 >= n || j1 < 0 || j2 < 0) return 0;
        if(i == m-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        // Explore all 9 possbilities
        int maxi = -1;
        for(int dj1 = -1; dj1 <= 1; ++dj1){
            for(int dj2 = -1; dj2 <= 1; ++dj2){
                int newJ1 = j1 + dj1;
                int newJ2 = j2 + dj2;

                maxi = max(maxi, solve(i+1, newJ1, newJ2, dp, grid));
            }
        }
        return dp[i][j1][j2] = maxi + curr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n-1, dp, grid);
    }
};