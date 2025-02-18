class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findParent(parent[i]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        // Find the maximum row index to calculate shifting for column indices
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Initialize DSU with enough nodes to handle both row and column indices
        DSU dsu(maxRow + maxCol + 2);  //+2 bcz nodes are from 0->maxRow and 0->maxCol, so 2 zeros

        // Process each stone, applying the shifting formula for the column index
        for (auto& stone : stones) {
            int rowNode = stone[0];                     // Row index of the current stone
            int colNode = stone[1] + maxRow + 1;        // Shift column index to avoid overlap
            dsu.unionBySize(rowNode, colNode);           // Union the row and column nodes in DSU
        }

        // Set to store unique connected components based on DSU parent
        unordered_set<int> stoneNodes;

        // Iterate through stones and insert their parent into the set
        for (auto& stone : stones) {
            stoneNodes.insert(dsu.findParent(stone[0]));  // Find the root of each row node
        }

        // The number of stones that can be removed is the total number of stones minus the number of unique connected components
        return stones.size() - stoneNodes.size();
    }
};

