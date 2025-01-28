class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, long long>>>adj(n);
        for(auto e : roads){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<long long, long long>,
            vector<pair<long long, long long>>, 
            greater<pair<long long, long long>>
            >pq;
    
        pq.push({0, 0});
        // {node, dist}
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = (int)1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long currDist = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            if(currDist > dist[currNode]) continue;

            for(auto nbr : adj[currNode]){
                long long nbrNode = nbr.first;
                long long nbrDist = nbr.second;
                
                // if reaching nbrNode with min dist for the first time
                if(currDist + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = currDist + nbrDist;
                    ways[nbrNode] = ways[currNode]; // Carry forward the number of ways
                    pq.push({dist[nbrNode], nbrNode});
                }
                //if a node has already been reached with the least posible dist, 
                // then this time, add the num of ways of curr and nbr

                 // If we found another way to reach the same distance to the neighbor node
                else if(currDist + nbrDist == dist[nbrNode]){
                    ways[nbrNode] = (ways[nbrNode] + ways[currNode]) % mod; // Add the ways
                }
            }
        }
        return ways[n-1] % mod;

    }
};
