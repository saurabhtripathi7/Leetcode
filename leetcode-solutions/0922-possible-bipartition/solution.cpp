class Solution {
public:
    bool dfs(int curr, vector<vector<int>>& adj, vector<int>& vis, vector<bool>& team, int currTeam){
        vis[curr] = 1;
        team[curr] = currTeam;

        for(auto nbr: adj[curr]){
            if(!vis[nbr]){
                if(dfs(nbr, adj, vis, team, !currTeam) == false){
                    return false; //propagate false
                }
            }
            else if(team[nbr] == currTeam) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        //int m = dislikes[0].size();
        vector<vector<int>> adj(n + 1); // Use n+1 for 1-based indexing
        for (auto& edge : dislikes) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);     // Add edges for both directions
        }

        vector<bool>team(n+1, 0);
        vector<int>vis(n+1, 0);

        for(int i = 1; i <= n; ++i){
            if(!vis[i]){
                if(dfs(i, adj, vis, team, 0) == false){
                    return false;
                }
            }
        }
        return true;        
    }
};
