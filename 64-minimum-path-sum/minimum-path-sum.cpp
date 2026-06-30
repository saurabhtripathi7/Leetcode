class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>prev(n, 0);
        prev[0] = grid[0][0];
        // init with Running sum of 1st row
        for(int j = 1; j < n; ++j) prev[j] = grid[0][j] + prev[j-1]; 

        for(int i = 1; i < m; ++i){
            vector<int>curr(n, 0);
            for(int j = 0; j < n; ++j){
                int left = j == 0 ? INT_MAX : curr[j-1];
                int up = prev[j];
                curr[j] = grid[i][j] + min(left, up);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};