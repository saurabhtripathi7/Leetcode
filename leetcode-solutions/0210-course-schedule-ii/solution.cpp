class Solution {
public:
    bool isCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& currPathVis, vector<int>& result) {
        vis[node] = true;  // Mark the node as visited
        currPathVis[node] = true;  // Mark the node as part of the current recursion stack

        // Explore all the neighbors
        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {  // If the neighbor is not visited, perform DFS on it
                if (isCycleDFS(nbr, adj, vis, currPathVis, result)) {
                    return true;  // If cycle is detected in any neighbor, return true
                }
            }
            else if (currPathVis[nbr]) {  // If the neighbor is visited and part of current recursion stack, cycle is detected
                return true;
            }
        }

        currPathVis[node] = false;  // Backtrack: remove the node from current recursion stack
        result.push_back(node);  // Push the node to the result after processing its neighbors
        return false;  // No cycle detected
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);  // To track visited nodes
        vector<bool> currPathVis(numCourses, false);  // To track nodes in the current recursion stack
        vector<int> result;

        // Initialize the adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            int u = edge[1];  // prerequisite course
            int v = edge[0];  // course that depends on the prerequisite
            adj[u].push_back(v);  // Add edge from u to v (u must be taken before v)
        }

        // Run DFS from each unvisited node
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i]) {
                if (isCycleDFS(i, adj, vis, currPathVis, result)) {
                    return {};  // If cycle is detected, return an empty list
                }
            }
        }

        // Since we added nodes in reverse post-order, reverse the result for correct topological order
        reverse(result.begin(), result.end());
        return result;
    }
};

