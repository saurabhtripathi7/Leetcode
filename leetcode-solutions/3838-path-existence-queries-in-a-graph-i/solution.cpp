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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                dsu.unionBySize(i, i + 1);  
            }
        }
        
        vector<bool> result;
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            result.push_back(dsu.findParent(u) == dsu.findParent(v));
        }
        
        return result;
    }
};
