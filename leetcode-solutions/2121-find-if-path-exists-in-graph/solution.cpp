class Solution {
public:
    bool ans = false;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n, false);

        queue<int>q;
        q.push(source);
        vis[source] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            if(u == destination) ans = true;

            for(auto nbr: adj[u]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        return ans;


    }
};
