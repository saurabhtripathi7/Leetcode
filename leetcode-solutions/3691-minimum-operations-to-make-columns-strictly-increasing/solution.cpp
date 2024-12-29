class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int op = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for (int col = 0; col < m; ++col) {
            for (int row = 1; row < n; ++row) {
                if (grid[row - 1][col] >= grid[row][col]) {
                    int increment = grid[row - 1][col] - grid[row][col] + 1;
                    op += increment;
                    grid[row][col] += increment;
                }
            }
        }
        return op;
    }
};

