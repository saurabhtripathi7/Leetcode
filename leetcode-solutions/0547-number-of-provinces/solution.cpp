class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        // If the node is already visited, return
        if (vis[node]) return;

        vis[node] = true; // Mark the current node as visited

        // Explore all neighbors of the current node
        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis); // Perform DFS on unvisited neighbors
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size(); // Number of nodes (vertices)
        
        // Convert adjacency matrix to adjacency list
        vector<vector<int>> adj(v);
        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(v, false); // Visited array to track visited nodes

        int cnt = 0; // Counter for the number of connected components (provinces)
        for (int i = 0; i < v; ++i) {
            if (!vis[i]) { // If a node is not visited, it's a new component
                cnt++;
                dfs(i, adj, vis); // Perform DFS to visit all nodes in this component
            }
        }
        return cnt; // Return the total number of provinces
    }
};

