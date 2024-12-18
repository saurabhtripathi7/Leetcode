class Solution {
public:
    bool dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int pRow, int pCol, int delRow[], int delCol[]) {
        vis[row][col] = 1; // mark the current cell as visited

        int n = grid.size();
        int m = grid[0].size();

        // Check all 4 directions
        for(int i = 0; i < 4; ++i) {
            int nr = row + delRow[i]; // calculate the new row index
            int nc = col + delCol[i]; // calculate the new column index

            // Ensure the new position is valid and is of the same character as the current cell
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[row][col] == grid[nr][nc] && !vis[nr][nc]) {
                // Recursively visit the next cell; exclude the parent cell (pRow, pCol) to avoid trivial backtracking
                if(dfs(nr, nc, grid, vis, row, col, delRow, delCol) == false) {
                    return false; // propagate false if a cycle is found
                }
            }
            // If the neighbor is already visited and is not the parent, a cycle is detected
            else if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[row][col] == grid[nr][nc] && (nr != pRow || nc != pCol)) {
                return false; // a cycle is detected
            }
        }

        return true;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited array to keep track of visited cells

        int delRow[] = {-1, 0, 1, 0}; // direction deltas for moving up, right, down, left
        int delCol[] = {0, 1, 0, -1};

        // Start DFS from each unvisited cell
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!vis[i][j]) {
                    // Perform DFS, if a cycle is found, return true
                    if(dfs(i, j, grid, vis, -1, -1, delRow, delCol) == false) {
                        return true;
                    }
                }
            }
        }

        return false; // no cycle found
    }
};

