class Solution {
public:
    void bfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int& nodes, int& edges){
        queue<int>q;
        q.push(u);
        
        vis[u]=true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            nodes++;

            for(auto nbr: adj[f]){
                edges++;
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n, false);

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                int edges = 0;
                int nodes = 0;

                bfs(i, adj, vis, nodes, edges);

                edges = edges/2;

                if(edges == nodes*(nodes-1)/2) 
                cnt++;
            }
        }
        return cnt;
    }
};
