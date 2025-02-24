class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0); // Initialize rank to 0
        for (int i = 0; i < n; ++i)
            parent[i] = i; // Each node is its own parent initially
    }

    int findParent(int i) {
        if (parent[i] == i)
            return i; // If the node is its own parent, return it
        return parent[i] = findParent(parent[i]); // Path compression
    }

    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV)
            return; // Already in the same set

        // Attach the smaller tree to the larger one
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV; // Root of U becomes child of Root V
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU; // Root of V becomes child of Root U
        } else {
            parent[rootV] = rootU; // Arbitrarily attach V to U
            rank[rootU]++;         // Increase rank if both have the same rank
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        // make components using DSU
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            dsu.unionByRank(u, v);
        }
        // store size of each compo in map {comp->size}
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; ++i) {
            int root_i = dsu.findParent(i);
            mpp[root_i]++; // representative of group -> size
        }
        // find result
        //  Total possible pairs among n nodes
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long internalPairs = 0; // To track intra-component pairs

        // Subtract internal pairs within each component
        for (const auto& [root, size] : mpp) {
            internalPairs += (long long)size * (size - 1) / 2;
        }

        // Valid inter-component pairs
        long long result = totalPairs - internalPairs;

        return result;
    }
};
