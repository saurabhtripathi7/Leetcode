class Solution {
public:
    bool hasCycleDFS(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 2;  // Mark the node as visited and currPathVis also

        // Explore all the neighbors
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {  // If the neighbor is not visited, perform DFS on it
                if (hasCycleDFS(nbr, adj, vis)) {
                    return true;  // If cycle is detected in any neighbor, return true
                }
            }
            else if (vis[nbr] == 2) {  // If the neighbor is visited and part of current recursion stack, cycle is detected
                return true;
            }
        }

        vis[node] = 1;  // Backtrack: remove the node from current recursion stack
        return false;  // No cycle detected
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);  // 0 = unvis ; 1 = vis; 2 = currPathVis
        
        // Initialize the adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            int u = edge[1];  // prerequisite course
            int v = edge[0];  // course that depends on the prerequisite
            adj[u].push_back(v);  // Add edge from u to v (u must be taken before v)
        }

        // Run DFS from each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i] && hasCycleDFS(i, adj, vis)) {
                return false;  // If cycle is detected, immediately return false
            }
        }

        return true;  // No cycle detected, all courses can be finished
    }
};

