class Solution {
public:
    // Helper function for Depth First Search (DFS)
    long long dfs(vector<vector<int>>& adj, vector<int>& nodeValues, int k, int& validCount, int currentNode, int parentNode) {
        long long sum = nodeValues[currentNode]; // Start with the value of the current node
        
        // Explore all the neighbors of the current node
        for (int neighbor : adj[currentNode]) {
            // Skip the parent node to avoid cycles in an undirected graph
            if (neighbor != parentNode) {
                sum += dfs(adj, nodeValues, k, validCount, neighbor, currentNode); // Recursively visit the neighbors
            }
        }
        
        sum %= k; // Take the sum modulo k to check divisibility
        if (sum == 0) validCount++; // If sum is divisible by k, increment validCount
        
        return sum; // Return the sum of the current node and its neighbors
    }

    // Main function to count components where the sum of node values is divisible by k
    int maxKDivisibleComponents(int numNodes, vector<vector<int>>& edges, vector<int>& nodeValues, int k) {
        vector<vector<int>> adj(numNodes); // Initialize adjacency list for the graph
        
        // Build the graph by adding edges to the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // Since it's an undirected graph
        }
        
        int validCount = 0; // Initialize counter for valid components
        dfs(adj, nodeValues, k, validCount, 0, -1); // Start DFS from node 0 with no parent
        
        return validCount; // Return the number of valid components
    }
};

