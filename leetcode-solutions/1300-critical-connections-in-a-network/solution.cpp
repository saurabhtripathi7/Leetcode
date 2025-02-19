class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>>&adj, vector<int>&disc, vector<int>& low, vector<bool>& vis, vector<vector<int>>& bridges, int &timer){
        vis[node] = 1;
        disc[node] = low[node] = timer;

        for(const auto &nbr : adj[node]){
            //Case 1: when nbr = parent, skip
            if(nbr == parent) continue;
            //Case 2: when nbr is already vis
            else if(vis[nbr] == true){
                low[node] = min(low[node], low[nbr]);  
            }
            //Case 3: when nbr is not visited 
            else{
                timer++;
                DFS(nbr, node, adj, disc, low, vis, bridges, timer);

                low[node] = min(low[node], low[nbr]);

                if(low[nbr] > disc[node]){
                    //edge is a bridge
                    bridges.push_back({node, nbr});
                }
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //Building the graph
        vector<vector<int>>adj(n);
        for(const auto &edge: connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>disc(n), low(n);
        vector<vector<int>>bridges;
        vector<bool>vis(n, false);
        int timer = 0;

        DFS(0, -1, adj, disc, low, vis, bridges, timer);
        
        return bridges;

    }
};
