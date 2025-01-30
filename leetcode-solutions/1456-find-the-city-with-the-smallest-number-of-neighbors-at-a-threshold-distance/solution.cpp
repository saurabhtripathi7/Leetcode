class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int minNbrs = INT_MAX, ansCity = -1;

        // Step 2: Run Dijkstra's Algorithm for each city
        for (int src = 0; src < n; ++src) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            vector<int> dist(n, INT_MAX);

            dist[src] = 0;
            pq.emplace(0, src);  // {distance, node}

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u]) continue;  // Ignore stale entries

                for (auto& [v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }

            // Step 3: Count reachable cities
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            // Step 4: Find the city with the minimum reachable neighbors
            if (count <= minNbrs) {
                minNbrs = count;
                ansCity = src;  // If tie, larger index will be selected
            }
        }

        return ansCity;
    }
};

