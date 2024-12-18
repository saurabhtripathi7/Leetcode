class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& ans) {
        // Initialize an array to track which flowers are used by adjacent
        // gardens
        vector<bool> used(5, false);

        // Mark the flowers used by the neighbors of the current garden
        for (auto nbr : adj[curr]) {
            if (ans[nbr] != 0) {
                used[ans[nbr]] = true; // Mark flower used by neighboring garden
            }
        }

        // Try assigning a flower that isn't used by adjacent gardens
        for (int flower = 1; flower <= 4; ++flower) {
            if (!used[flower]) {
                ans[curr] = flower; // Assign flower to current garden
                break;
            }
        }

        vis[curr] = 1; // Mark current garden as visited

        // Now, visit all the neighboring gardens (DFS)
        for (auto nbr : adj[curr]) {
            if (!vis[nbr]) {
                if (!dfs(nbr, adj, vis, ans)) {
                    return false; // If any neighbor can't be assigned a valid flower, return false
                }
            }
        }

        return true; // If we assigned flowers to all neighbors, return true
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Create adjacency list
        vector<vector<int>> adj(n + 1); // Use n+1 for 1-based indexing
        for (auto& edge : paths) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);     // Add edges for both directions
        }

        vector<int> vis(n + 1, 0);  // Visited array to track visited gardens
        vector<int> ans(n + 1, 0);  // Array to store the flower assignments

        // Perform DFS for each garden
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis, ans);  // Call DFS for unvisited garden
            }
        }

        return vector<int>(ans.begin() + 1, ans.end());  // Return flower assignments (excluding index 0)
    }
};

