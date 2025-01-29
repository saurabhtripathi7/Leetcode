class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto e: times){
            adj[e[0]].push_back({e[1], e[2]});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        >pq;
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if(currDist > dist[currNode]) continue;
            
            for(auto nbr : adj[currNode]){
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if(nbrDist + currDist < dist[nbrNode]){
                    dist[nbrNode] = nbrDist + currDist;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
