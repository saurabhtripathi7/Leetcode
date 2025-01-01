class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        if(vis[node]) return;

        vis[node] = 1;
        
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int rows = connections.size();
        if(rows < n-1) return -1;

        int col = connections[0].size();

        vector<vector<int>> adj(n);

        for(auto edge: connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n ,0);
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt-1;
    }
};
