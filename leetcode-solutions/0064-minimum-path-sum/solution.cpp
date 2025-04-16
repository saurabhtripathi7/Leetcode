class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return grid[0][0]; //bcz this value will be part of the ans & and passed on
        if( i < 0 || j < 0) return INT_MAX; //for invalid path, return such a value that cant be minimum
        if(dp[i][j] != -1) return dp[i][j];

        int up = i > 0 ? solve(i-1, j, m, n, grid, dp) : INT_MAX;
        int left = j > 0 ? solve(i, j-1, m, n, grid, dp) : INT_MAX;

        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, m, n, grid, dp); //from bottom to top corner
    }
};

/*
TC : O(m*n) bcz The total number of recursive calls can be at max m*n
SC : O(m*n) bcz of dp + O(m + n) bcz of rec stack space (because in the worst case, you may need to recurse along a path from one corner to the opposite corner, which would result in a maximum of m + n recursive calls on the stack at any point in time.) 
*/
