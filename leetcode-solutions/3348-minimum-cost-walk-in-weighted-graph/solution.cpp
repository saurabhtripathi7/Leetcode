class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int parentFind(int a) {
        if (parent[a] != a)
            parent[a] = parentFind(parent[a]);  // Path compression
        return parent[a];
    }

    void Union(int a, int b) {
        int rootA = parentFind(a);
        int rootB = parentFind(b);
        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int> componentAND(n, (1 << 18) - 1);  // Initialize with all bits set (max weight ≤ 10^5)
        vector<bool> hasEdge(n, false);  // Track components that have at least one edge

        // First, perform union operations
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dsu.Union(u, v);
        }

        // Compute AND for each connected component
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int root = dsu.parentFind(u);
            componentAND[root] &= w;
            hasEdge[root] = true;
        }

        vector<int> result;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            if (dsu.parentFind(s) != dsu.parentFind(t)) {
                result.push_back(-1);
            } else {
                int root = dsu.parentFind(s);
                result.push_back(hasEdge[root] ? componentAND[root] : -1);
            }
        }

        return result;
    }
};
