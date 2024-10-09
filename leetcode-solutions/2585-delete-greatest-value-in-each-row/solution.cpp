class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int total = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        // Sort each row in descending order to always get the largest value at the front
        for (int i = 0; i < rows; ++i) {
            sort(grid[i].begin(), grid[i].end(), greater<int>());
        }

        // Traverse column-wise to get the maximum element of each column
        for (int j = 0; j < cols; ++j) {
            int maxVal = 0;
            for (int i = 0; i < rows; ++i) {
                maxVal = max(maxVal, grid[i][j]);
            }
            total += maxVal;  // Add the maximum value from the column
        }

        return total;
    }
};

