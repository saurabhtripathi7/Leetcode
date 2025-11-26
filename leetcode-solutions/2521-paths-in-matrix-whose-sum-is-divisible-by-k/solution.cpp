class Solution {
public:
    int n, m;
    
    int solve(int i, int j, int val, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
        if(i >= n || j >= m) return 0;
        if(i == n-1 && j == m-1){
            if((val+grid[i][j])%k== 0){
                return 1;
            }
            else return 0;
        }

        if(dp[i][j][val] != -1) return dp[i][j][val];
        
        int right = solve(i, j+1, (val+grid[i][j])%k, k,grid, dp);
        int down = solve(i+1, j, (val+grid[i][j])%k, k, grid, dp);

        return dp[i][j][val] = (right + down)%(int)(1e9+7);


    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(k,-1)));

        return solve(0,0,0, k, grid, dp);
    }
};
