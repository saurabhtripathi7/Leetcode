static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    int n;

    int dfs(int i, int j, vector<vector<int>>& grid, int index) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return 0;
        
        grid[i][j] = index;
        int sum = 1;
        
        for (int x = 0; x < 4; ++x) {
            sum += dfs(i + dr[x], j + dc[x], grid, index);
        }
        return sum;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;  // Stores size of each island
        int index = 2, maxArea = 0;
        bool allOnes = true;

        // Step 1: Identify islands and store their sizes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, grid, index);
                    islandSize[index] = area;
                    maxArea = max(maxArea, area);
                    index++;
                } else {
                    allOnes = false;
                }
            }
        }

        if (allOnes) return n * n;

        // Step 2: Try flipping each 0 and compute max area
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int sum = 1; // Flip this 0 to 1

                    for (int x = 0; x < 4; ++x) {
                        int nr = i + dr[x], nc = j + dc[x];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] > 1) {
                            uniqueIslands.insert(grid[nr][nc]);
                        }
                    }

                    for (int idx : uniqueIslands) {
                        sum += islandSize[idx];
                    }

                    maxArea = max(maxArea, sum);
                }
            }
        }
        return maxArea;
    }
};

