class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        // Using nested loops to explore the four directions (up, down, left, right)
        while (!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            // Explore all 8 possible directions (but skip diagonals later)
            for (int dRow = -1; dRow <= 1; ++dRow) {
                for (int dCol = -1; dCol <= 1; ++dCol) {
                    // Skip diagonal directions (i.e., if abs(dRow) + abs(dCol) == 2)
                    if (abs(dRow) + abs(dCol) == 2) continue;

                    int nbrRow = currRow + dRow;
                    int nbrCol = currCol + dCol;

                    // Check bounds and visit only unvisited land cells
                    if (nbrRow >= 0 && nbrRow < n && nbrCol >= 0 && nbrCol < m 
                        && grid[nbrRow][nbrCol] == '1' && !vis[nbrRow][nbrCol]) {
                        vis[nbrRow][nbrCol] = 1;
                        q.push({nbrRow, nbrCol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited matrix
        int cnt = 0;

        // Iterate through every cell in the grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (!vis[row][col] && grid[row][col] == '1') { // Start BFS for new island
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};

