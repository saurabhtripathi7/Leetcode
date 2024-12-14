class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Visited array to track visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Push boundary cells with land (1) into the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // Boundary condition
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1; // Mark as visited
                    }
                    
                }
            }
        }

        // Directions for moving up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS to mark all reachable land cells from the boundary
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                // Check if the neighbor is within bounds, not visited, and is land
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1; // Mark as visited
                    q.push({nr, nc}); // Add to queue
                }
            }
        }

        // Count unvisited land cells (enclaves)
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    cnt++; // Increment count for enclaves
                }
            }
        }

        return cnt;
    }
};

