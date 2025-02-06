class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Step 1: Build the adjacency list
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        // Step 2: Initialize the priority queue, distance array, and ways array
        priority_queue<pair<long long, long long>, 
                       vector<pair<long long, long long>>, 
                       greater<pair<long long, long long>>> pq;
        pq.push({0, 0}); // {dist, node}

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        int mod = 1e9 + 7;

        dist[0] = 0;  // Distance to source node is 0
        ways[0] = 1;  // There's exactly 1 way to reach the source node (itself)

        // Step 3: Dijkstra's algorithm with counting paths
        while (!pq.empty()) {
            long long currDist = pq.top().first;
            long long currNode = pq.top().second;
            pq.pop();

            // Skip processing if the distance is outdated (we’ve already found a shorter path)
            if (currDist > dist[currNode]) continue;

            // Step 4: Process each neighbor of the current node
            for (auto& nbr : adj[currNode]) {
                long long nbrNode = nbr.first;
                long long nbrDist = nbr.second;

                // Case 1: Found a shorter path to the neighbor node
                if (currDist + nbrDist < dist[nbrNode]) {
                    dist[nbrNode] = currDist + nbrDist;
                    ways[nbrNode] = ways[currNode];  // Carry forward the number of ways
                    pq.push({dist[nbrNode], nbrNode});
                }
                // Case 2: Found another way to reach the same distance to the neighbor node
                else if (currDist + nbrDist == dist[nbrNode]) {
                    ways[nbrNode] = (ways[nbrNode] + ways[currNode]) % mod; // Add the ways
                }
            }
        }

        // Step 5: Return the number of ways to reach the destination node (n-1)
        return ways[n - 1] % mod;
    }
};

