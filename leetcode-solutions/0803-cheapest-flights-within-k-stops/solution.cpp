class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Create an adjacency list to represent the graph.
        // Each key represents a city, and its value is a list of pairs {neighbor_city, flight_cost}.
        unordered_map<int, vector<pair<int, int>>> adjacencyList;
        for (auto flight : flights) {
            adjacencyList[flight[0]].push_back({flight[1], flight[2]});
        }

        // Min-heap (priority queue) to store {total_cost, current_city, total_stops}.
        // It ensures paths with the smallest total_cost are processed first.
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, src, 0}); // Start with {total_cost = 0, current_city = src, total_stops = 0}.
        
        // MinStopsToCity array to track the minimum number of stops required to reach each city.
        vector<int> minStopsToCity(n + 1, INT_MAX);

        // Process the priority queue until it's empty.
        while (!minHeap.empty()) {
            auto currentPath = minHeap.top(); // Get the path with the smallest total_cost.
            minHeap.pop();
            int currentCost = currentPath[0];  // Current total cost.
            int currentCity = currentPath[1]; // Current city.
            int stopsTaken = currentPath[2];  // Number of stops taken so far.

            // If the current path exceeds the allowed number of stops or is less optimal, skip it.
            if (stopsTaken > minStopsToCity[currentCity] || stopsTaken > K + 1) continue;

            // Update the minStopsToCity array with the current step count as it's the optimal path so far.
            minStopsToCity[currentCity] = stopsTaken;

            // If we reach the destination city, return the currentCost.
            if (currentCity == dst) {
                return currentCost;
            }

            // Add all neighboring cities of the current city to the heap with updated cost and stops.
            for (auto neighbor : adjacencyList[currentCity]) {
                minHeap.push({currentCost + neighbor.second, neighbor.first, stopsTaken + 1});
            }
        }

        // If no valid path to the destination is found, return -1.
        return -1;
    }
};

