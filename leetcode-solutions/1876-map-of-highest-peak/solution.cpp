class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;

        // Initialize the queue and set heights for water cells
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0; // Water cells have height 0
                }
            }
        }

        // Directions for exploring neighbors (up, down, left, right)
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int dx = dir[0], dy = dir[1];
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};

