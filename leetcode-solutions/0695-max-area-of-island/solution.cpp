class DSU {
public:
    vector<int> parent, rank, size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findParent(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV)
            return;

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DSU dsu(n * m);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Apply Union-Find only on land cells (`1`s)
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    int currCell = row * m + col;
                    for (int i = 0; i < 4; ++i) {
                        int nr = row + dr[i];
                        int nc = col + dc[i];

                        if (isValid(nr, nc, n, m) && grid[nr][nc] == 1) {
                            int adjCell = nr * m + nc;
                            dsu.unionBySize(currCell, adjCell);
                        }
                    }
                }
            }
        }

        // Step 2: Find the largest island size
        int maxi = 0;
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == 1) {
                    int root = dsu.findParent(row * m + col);
                    maxi = max(maxi, dsu.size[root]);  // Track max island size
                }
            }
        }

        return maxi;
    }
};

