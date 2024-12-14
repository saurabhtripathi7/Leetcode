class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); // Number of rows in the matrix
        int n = mat[0].size(); // Number of columns in the matrix

        // Queue to perform BFS. Stores pairs: {{row, col}, distance}
        queue<pair<pair<int,int>, int>> q;

        // Visited matrix to avoid revisiting cells
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Resultant distance matrix
        vector<vector<int>> dist(m, vector<int>(n, 0));

        // Initialize BFS queue with all cells having value 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) { 
                    q.push({{i, j}, 0}); // Push cell coordinates and distance 0
                    vis[i][j] = 1; // Mark cell as visited
                }
            }
        }

        // Direction arrays to explore neighbors (up, right, down, left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS loop
        while (!q.empty()) {
            // Extract front element from the queue
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second; // Current distance from a 0 cell
            q.pop();

            // Update the distance for the current cell
            dist[row][col] = steps;

            // Explore all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = row + delRow[i]; // New row
                int nc = col + delCol[i]; // New column

                // Check if the neighbor is within bounds and unvisited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1; // Mark neighbor as visited
                    q.push({{nr, nc}, steps + 1}); // Push neighbor with updated distance
                }
            }
        }

        return dist; // Return the resultant distance matrix
    }
};

