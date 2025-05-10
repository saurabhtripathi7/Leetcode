class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].emplace_back(e[1], e[2]);
        }

        // seen[u][used] = set of sums
        vector<vector<unordered_set<int>>> seen(n, vector<unordered_set<int>>(k + 1));

        // Queue: (node, sum, used)
        queue<tuple<int, int, int>> q;

        // Initialize: used = 0, sum = 0 at every node
        for (int u = 0; u < n; ++u) {
            seen[u][0].insert(0);
            q.emplace(u, 0, 0);  // (node, sum, used)
        }

        // BFS loop
        while (!q.empty()) {
            auto [u, sum, used] = q.front(); q.pop();

            if (used == k) continue;  // Don't go deeper than k edges

            for (auto &[v, w] : graph[u]) {
                int ns = sum + w;
                if (ns < t && seen[v][used + 1].insert(ns).second) {
                    q.emplace(v, ns, used + 1);
                }
            }
        }

        // After BFS, scan for max sum < t at exactly k edges
        int ans = -1;
        for (int u = 0; u < n; ++u) {
            for (int s : seen[u][k]) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};

