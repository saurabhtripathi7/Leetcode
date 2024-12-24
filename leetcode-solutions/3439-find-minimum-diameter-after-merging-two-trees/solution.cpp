#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to calculate the diameter of a tree
    int calculateTreeDiameter(const vector<pair<int, int>>& edges) {
        if (edges.empty()) return 0;

        unordered_map<int, vector<int>> graph;

        // Build the adjacency list
        for (auto& edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        // Helper function to perform BFS
        auto bfs = [&](int start) -> pair<int, int> {
            queue<pair<int, int>> q;
            unordered_map<int, bool> visited;
            q.push({start, 0});
            visited[start] = true;

            int farthestNode = start, maxDistance = 0;

            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();

                if (dist > maxDistance) {
                    maxDistance = dist;
                    farthestNode = node;
                }

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, dist + 1});
                    }
                }
            }
            return {farthestNode, maxDistance};
        };

        // Perform BFS twice to find the diameter
        int farthestFromStart = bfs(edges[0].first).first;  // Start BFS from any node
        int diameter = bfs(farthestFromStart).second;      // Find diameter from farthest node

        return diameter;
    }

    // Function to calculate the minimum diameter after merging two trees
    int minimumDiameterAfterMerge(const vector<vector<int>>& edges1, const vector<vector<int>>& edges2) {
        // Convert edges1 and edges2 from vector<vector<int>> to vector<pair<int, int>>
        vector<pair<int, int>> tree1 = convertEdges(edges1);
        vector<pair<int, int>> tree2 = convertEdges(edges2);

        // Calculate diameters of both trees
        int diameter1 = calculateTreeDiameter(tree1);
        int diameter2 = calculateTreeDiameter(tree2);

        // Calculate the minimum possible diameter after merging
        int mergeDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;
        return max({diameter1, diameter2, mergeDiameter});
    }

private:
    // Helper function to convert vector<vector<int>> to vector<pair<int, int>>
    vector<pair<int, int>> convertEdges(const vector<vector<int>>& edges) {
        vector<pair<int, int>> result;
        for (const auto& edge : edges) {
            if (edge.size() == 2) {
                result.emplace_back(edge[0], edge[1]);
            }
        }
        return result;
    }
};

