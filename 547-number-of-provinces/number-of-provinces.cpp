class Solution {
public:
    void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj){
        if(vis[u]) return;

        vis[u] = true;

        for(auto nbr : adj[u]){
            dfs(nbr, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n, false);
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }

        return cnt;
    }
};