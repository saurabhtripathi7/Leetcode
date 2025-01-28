class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        // If the current cell is out of bounds or water (0) or already visited
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0 || vis[r][c]) {
            return 0;
        }
        
        // Mark the cell as visited
        vis[r][c] = true;
        
        // Initialize the area of the current island to 1 (the current land cell)
        int area = 1;

        // Define the 4 possible directions (up, right, down, left)
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Explore all 4 directions
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            area += dfs(nr, nc, grid, vis);  // Accumulate the area
        }
        
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // Create a visited matrix to track which cells have been visited
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        
        int maxArea = 0;
        
        // Traverse all cells of the grid
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // If the cell is land and hasn't been visited
                if (grid[i][j] == 1 && !vis[i][j]) {
                    // Start DFS to explore the island and calculate its area
                    int area = dfs(i, j, grid, vis);
                    maxArea = max(maxArea, area);  // Update max area if needed
                }
            }
        }
        
        return maxArea;  // Return the largest island area found
    }
};

