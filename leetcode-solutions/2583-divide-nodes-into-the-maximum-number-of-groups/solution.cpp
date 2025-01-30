class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        
        // Build the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1); // -1: uncolored, 0: color1, 1: color2
        vector<int> visited(n + 1, 0);
        int maxGroups = 0;
        
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) { // Not colored, new component
                queue<int> q;
                q.push(i);
                color[i] = 0;

                vector<int> component;
                component.push_back(i);
                
                bool isBipartite = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                            component.push_back(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            // Found an odd cycle (not bipartite)
                            return -1;
                        }
                    }
                }

                // Run BFS to find the longest path in the component
                int maxDepth = 0;
                for (int start : component) {
                    maxDepth = max(maxDepth, bfsDepth(start, adj));
                }
                
                maxGroups += maxDepth;
            }
        }
        
        return maxGroups;
    }

private:
    int bfsDepth(int src, vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> dist(adj.size(), -1);
        
        q.push(src);
        dist[src] = 0;
        int maxDepth = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            maxDepth = max(maxDepth, dist[node]);

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return maxDepth + 1; // Number of groups is depth + 1
    }
};

