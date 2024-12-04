class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto nbr:rooms[u]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }

        for(auto i : vis){
                if(i==false) return false;
        }
        return true;
    }
};
