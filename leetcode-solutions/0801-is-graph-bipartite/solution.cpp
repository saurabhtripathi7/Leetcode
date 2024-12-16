class Solution {
public:
    bool checkBipartiteBFS(int curr, vector<vector<int>>& graph, vector<int>& color, int currColor) {
        queue<int> q;
        q.push(curr);
        color[curr] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int nbr : graph[u]) {
                if (color[nbr] == color[u]) {
                    return false; // Same color as parent, not bipartite
                } else if (color[nbr] == -1) { // Not yet colored
                    color[nbr] = !color[u]; // Assign the opposite color
                    q.push(nbr);
                }
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all nodes as uncolored (-1)
        
        // Iterate over each node in the graph
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) { // If node is not colored yet
                if (!checkBipartiteBFS(i, graph, color, 0)) {
                    return false; // If any component is not bipartite
                }
            }
        }
        
        return true;
    }
};

