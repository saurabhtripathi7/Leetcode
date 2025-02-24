class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionByRank(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

class Solution {
public:
    // Helper function to check if the neighbor is within bounds
    bool isValid(int row, int col, int m, int n) {
        return (row >= 0 && row < m && col >= 0 && col < n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m * n);

        // Helper function to convert 2D (i, j) to 1D index
        auto getIndex = [&](int i, int j) {
            return i * n + j;
        };

        // Direction vectors for 4 neighbors (up, down, left, right)
        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};

        // Traverse the grid and connect adjacent lands
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == '1') {
                    for (int i = 0; i < 4; ++i) {
                        int nbrRow = row + delRow[i];
                        int nbrCol = col + delCol[i];

                        // Check if neighbor is valid and is land
                        if (isValid(nbrRow, nbrCol, m, n) && grid[nbrRow][nbrCol] == '1') {
                            dsu.unionByRank(getIndex(row, col), getIndex(nbrRow, nbrCol));
                        }
                    }
                }
            }
        }

        // Use a set to find unique island roots
        unordered_set<int> uniqueIslands;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == '1') {
                    uniqueIslands.insert(dsu.findParent(getIndex(row, col)));
                }
            }
        }

        return uniqueIslands.size();
    }
};

