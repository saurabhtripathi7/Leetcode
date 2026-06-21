class Solution {
public:
    using t = tuple<int, int, int>;
    vector<vector<pair<int,int>>>adj;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        adj.resize(n);
        int len = labels.size();
        for(auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<vector<int>>dist(n, vector<int>(k+1,INT_MAX));
        priority_queue<t, vector<t>,greater<t>>pq;
        dist[0][1] = 0;
        pq.push({0,0,1});// {cost, node, streak}
        while(!pq.empty()){
            auto [cost, node, streak] = pq.top();
            pq.pop();

            for(auto &neigh : adj[node]){
                int v = neigh.first;
                int wt = neigh.second;
                int newStreak;
                if(labels[v]==labels[node]){
                    newStreak = streak+1;
                    if(newStreak > k){
                        continue;
                    }
                }else{
                    newStreak = 1;
                }

                if(cost + wt < dist[v][newStreak]){
                    dist[v][newStreak] = cost + wt;
                    pq.push({dist[v][newStreak], v, newStreak});
                }
                
            }
        }
        int ans = INT_MAX;
        for(int s = 1;s<=k;s++){
            ans = min(ans, dist[n-1][s]);
        }
        return ans==INT_MAX? -1 : ans;
    }
};