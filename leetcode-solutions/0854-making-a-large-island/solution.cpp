class DSU {
public:
    vector<int> parent, size;

    // Constructor to initialize the DSU (Disjoint Set Union) structure
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);  // Initialize size of each component as 1
        for (int i = 0; i < n; ++i) {
            parent[i] = i;  // Each node is its own parent initially
        }
    }

    // Find the parent (root) of the component that contains node x, with path compression
    int findParent(int x) {
        if (parent[x] == x) return x;  // If x is its own parent, return x
        return parent[x] = findParent(parent[x]);  // Path compression
    }

    // Union by size: Merge the smaller component into the larger one
    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;  // If they are already in the same component, do nothing

        // Merge the smaller component into the larger one
        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];  // Update size of the new root component
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];  // Update size of the new root component
        }
    }
};

class Solution {
public:
    // Check if the given row and column are within bounds of the grid
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n * n);  // Create DSU for all cells in the grid

        // Directions to move up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Process all the 1s in the grid and create disjoint sets
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    int currNode = row * n + col;  // Calculate node number for (row, col)
                    // Check all 4 neighbors (up, right, down, left)
                    for (int i = 0; i < 4; ++i) {
                        int nr = row + dr[i];
                        int nc = col + dc[i];

                        // If the neighbor is within bounds and is a 1, union the current cell and the neighbor
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            int adjNode = nr * n + nc;  // Calculate node number for neighbor
                            dsu.unionBySize(currNode, adjNode);  // Union the two nodes
                        }
                    }
                }
            }
        }

        // Step 2: Try flipping each 0 to 1 and calculate the new largest connected area
        int maxArea = 0;  // To store the maximum area of the island
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    int currCompSize = 1;  // 1 for the flipped 0 cell
                    unordered_set<int> st;  // To track unique connected components

                    // Check all 4 neighbors (up, right, down, left)
                    for (int i = 0; i < 4; ++i) {
                        int nr = row + dr[i];
                        int nc = col + dc[i];

                        // If the neighbor is within bounds and is a 1, add its component to the set
                        if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                            int adjNode = nr * n + nc;
                            int parentAdj = dsu.findParent(adjNode);  // Find the parent of the neighboring component

                            // If the component hasn't been added yet, add its size to the current island size
                            if (st.insert(parentAdj).second) {
                                currCompSize += dsu.size[parentAdj];
                            }
                        }
                    }
                    maxArea = max(maxArea, currCompSize);  // Update max area
                }
            }
        }

        // Step 3: If no 0's were flipped, check the size of the largest component
        for (int cellNo = 0; cellNo < n * n; ++cellNo) {
            maxArea = max(maxArea, dsu.size[dsu.findParent(cellNo)]);  // Find the largest connected component of 1's
        }

        return maxArea;  // Return the maximum area
    }
};

