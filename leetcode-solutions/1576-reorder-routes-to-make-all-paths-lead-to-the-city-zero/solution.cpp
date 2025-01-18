class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int& cnt) {

        vis[u] = true;

        for (auto nbr : adj[u]) {
            if (!vis[abs(nbr)]) {
                // If the edge is a forward edge (positive value), increment the count (count reversal)
                if (nbr > 0) cnt++;
                dfs(abs(nbr), adj, vis, cnt);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // Positive value represents a forward edge
        // Negative value represents a backward edge
        vector<vector<int>> adj(n);
        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);  // Add forward edge
            adj[c[1]].push_back(-c[0]); // Add backward edge
        }
        
        vector<bool> vis(n, false);
        int cnt = 0; 

        dfs(0, adj, vis, cnt);

        return cnt; 
    }
};

