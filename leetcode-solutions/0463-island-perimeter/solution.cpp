class Solution {
public:
    // Directions for moving up, right, down, and left
    int nrow[4] = {-1, 0, 1, 0};
    int ncol[4] = {0, 1, 0, -1};
    int n, m;

    // Function to check if the cell is within grid bounds
    bool isvalid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();    // Number of rows
        m = grid[0].size(); // Number of columns
        int ans = 0;        // Initialize perimeter count to 0

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check only land cells
                if (grid[i][j] == 1) {
                    ans += 4; // Start with 4 sides for the current land cell

                    // Check all 4 possible neighbors
                    for (int k = 0; k < 4; k++) {
                        int row = i + nrow[k];
                        int col = j + ncol[k];

                        // If a valid neighbor is also land, reduce one side
                        if (isvalid(row, col) && grid[row][col] == 1) {
                            ans--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

