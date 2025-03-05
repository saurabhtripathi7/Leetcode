class Solution {
public:
    bool isValid(int nr, int nc, int n, int m) {
        return nr >= 0 && nr < n && nc >= 0 && nc < m;
    }

    bool isSafeBFS(int currTime, vector<vector<int>>& grid, vector<vector<int>>& fire) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q; // {row, col, time}
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0, 0, currTime});
        vis[0][0] = true;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto front = q.front();
            int row = front[0];
            int col = front[1];
            int time = front[2];
            q.pop();

            // If we reach the safehouse, allow simultaneous arrival.
            if (row == n - 1 && col == m - 1) {
                if (fire[row][col] == -1 || fire[row][col] >= time)
                    return true;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (!isValid(nr, nc, n, m) || vis[nr][nc] || grid[nr][nc] == 2)
                    continue;
                
                if (nr == n - 1 && nc == m - 1) {
                    // For safehouse, allow if fire arrives at time+1 or later.
                    if (fire[nr][nc] == -1 || fire[nr][nc] >= time + 1) {
                        vis[nr][nc] = true;
                        q.push({nr, nc, time + 1});
                    }
                } else {
                    // For other cells, player must arrive strictly before the fire.
                    if (fire[nr][nc] == -1 || fire[nr][nc] > time + 1) {
                        vis[nr][nc] = true;
                        q.push({nr, nc, time + 1});
                    }
                }
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        
        queue<vector<int>> q;
        vector<vector<int>> fire(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                    fire[i][j] = 0;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto front = q.front();
            int row = front[0], col = front[1], time = front[2];
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (isValid(nr, nc, n, m) && fire[nr][nc] == -1 && grid[nr][nc] != 2) {
                    fire[nr][nc] = time + 1;
                    q.push({nr, nc, time + 1});
                }
            }
        }

        int low = 0, high = n * m, ans = -1;

        
        if (!isSafeBFS(0, grid, fire)) return -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isSafeBFS(mid, grid, fire)) {
                ans = mid;      
                low = mid + 1;   
            } else {
                high = mid - 1;  
            }
        }

        return (ans == n * m) ? 1e9 : ans;
    }
};

