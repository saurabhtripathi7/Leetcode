#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Min-Heap to store {time, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // Start from (0, 0) with initial time as grid[0][0]
        pq.emplace(grid[0][0], 0, 0);
        vis[0][0] = true;

        // 4-Directional movement (up, right, down, left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [currTime, row, col] = pq.top();
            pq.pop();
            
            // If we reached the bottom-right cell, return the time
            if (row == n - 1 && col == n - 1) return currTime;

            // Explore all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nbrRow = row + delRow[i];
                int nbrCol = col + delCol[i];

                // Check bounds and unvisited neighbors
                if (nbrRow >= 0 && nbrRow < n && nbrCol >= 0 && nbrCol < n && !vis[nbrRow][nbrCol]) {
                    vis[nbrRow][nbrCol] = true;
                    
                    // The time needed to reach the neighbor is max of current time and the neighbor's elevation
                    int newTime = max(currTime, grid[nbrRow][nbrCol]);
                    pq.emplace(newTime, nbrRow, nbrCol);
                }
            }
        }

        return -1; // Should never reach here
    }
};

