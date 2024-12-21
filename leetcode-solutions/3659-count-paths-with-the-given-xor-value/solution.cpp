class Solution {
public:
    int dfs(int i, int j, int currentXOR, const vector<vector<int>>& grid, int k, vector<vector<unordered_map<int, int>>>& memo) {
        int m = grid.size(), n = grid[0].size();

        // Base case: Reached bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return (currentXOR == k) ? 1 : 0;
        }

        // If already computed
        if (memo[i][j].count(currentXOR)) {
            return memo[i][j][currentXOR];
        }

        int paths = 0;

        // Move right
        if (j + 1 < n) {
            paths += dfs(i, j + 1, currentXOR ^ grid[i][j + 1], grid, k, memo);
        }

        // Move down
        if (i + 1 < m) {
            paths += dfs(i + 1, j, currentXOR ^ grid[i + 1][j], grid, k, memo);
        }

        // Store result in memo
        return memo[i][j][currentXOR] = paths % 1000000007;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // Use unordered_map for dynamic allocation of XOR values
        vector<vector<unordered_map<int, int>>> memo(m, vector<unordered_map<int, int>>(n));
        return dfs(0, 0, grid[0][0], grid, k, memo);
    }
};

