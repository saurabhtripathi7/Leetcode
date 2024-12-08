class Solution {
public:
    bool isCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& currPathVis) {
        vis[node] = true;  // Mark the node as visited
        currPathVis[node] = true;  // Mark the node as part of the current recursion stack

        // Explore all the neighbors
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {  // If the neighbor is not visited, perform DFS on it
                if (isCycleDFS(nbr, adj, vis, currPathVis)) {
                    return true;  // If cycle is detected in any neighbor, return true
                }
            }
            else if (currPathVis[nbr]) {  // If the neighbor is visited and part of current recursion stack, cycle is detected
                return true;
            }
        }

        currPathVis[node] = false;  // Backtrack: remove the node from current recursion stack
        return false;  // No cycle detected
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);  // To track visited nodes
        vector<bool> currPathVis(numCourses, false);  // To track nodes in the current recursion stack

        // Initialize the adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            int u = edge[1];  // prerequisite course
            int v = edge[0];  // course that depends on the prerequisite
            adj[u].push_back(v);  // Add edge from u to v (u must be taken before v)
        }

        // Run DFS from each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i] && isCycleDFS(i, adj, vis, currPathVis)) {
                return false;  // If cycle is detected, return false
            }
        }

        return true;  // No cycle detected, all courses can be finished
    }
};

