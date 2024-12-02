class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();          // Number of rows
        int m = grid[0].size();       // Number of columns
        int cntFresh = 0;             // Counter for fresh oranges
        queue<pair<pair<int, int>, int>> q; // Queue to hold the positions of rotten oranges and time
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        // Step 1: Initialize the queue with the positions of the rotten oranges
        // and count the fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Rotten orange added to queue with time 0
                    vis[i][j] = 2;         // Mark as visited (rotten)
                } else {
                    vis[i][j] = 0;         // Mark as not visited (fresh or empty)
                }
                if (grid[i][j] == 1) {
                    cntFresh++;            // Increment the count of fresh oranges
                }
            }
        }

        int time = 0;                   // Time to rot all oranges
        int row[] = {-1, 0, +1, 0};     // Direction array for moving in the grid (up, right, down, left)
        int col[] = {0, +1, 0, -1};     // Direction array for moving in the grid
        int cnt = 0;                    // Counter for the number of rotted oranges

        // Step 2: Perform BFS to rot the fresh oranges
        while (!q.empty()) {
            int r = q.front().first.first;  // Row index of rotten orange
            int c = q.front().first.second; // Column index of rotten orange
            int t = q.front().second;       // Time taken to rot the orange
            q.pop();
            time = max(time, t);            // Update the max time taken to rot oranges

            // Traverse the four adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];       // Calculate the next row index
                int ncol = c + col[i];       // Calculate the next column index
                // Check if the next position is valid, fresh, and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1}); // Add the fresh orange to the queue
                    vis[nrow][ncol] = 2;          // Mark as rotten
                    cnt++;                        // Increment the count of rotted oranges
                }
            }
        }

        // Step 3: Check if all fresh oranges have rotted
        if (cnt != cntFresh) return -1;  // If not all fresh oranges rotted, return -1
        return time;                     // Return the total time taken to rot all oranges
    }
};

