class Solution {
public:
    bool hasCycleDFS(int currNode, vector<vector<int>>& graph, vector<int>& vis, vector<int>& isSafe){
        // mark curr as vis and currPath Vis
        vis[currNode] = 2; 
        isSafe[currNode] = 0; //assume it as unsafe init

        for(int nbr : graph[currNode]){
            if(!vis[nbr]){
                if(hasCycleDFS(nbr, graph, vis, isSafe))
                return true;  //if nbr leads to cycle, propagate unsafety
            }
            else if(vis[nbr] == 2){
                return true; //if nbr is already present in the currPath, a cycle is detected
            }
        }

        isSafe[currNode] = 1; //if no cycle was detected for curr and none of its nbrs lead to cycle, mark it as safe
        vis[currNode] = 1; // remove curr from currPath while going back
        return false; //no cycle found!!
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //all nodes part of any cycle and all nodes leading to a cycle can't be safe
        //so using hasCycleDFS to check for cycles and collecting safeNodes
        int n = graph.size();
        vector<int>vis(n, 0);
        vector<int>isSafe(n, 0);

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                hasCycleDFS(i, graph, vis, isSafe);
            }
        }

        //building ans
        vector<int>safeNodes;
        for(int i = 0; i < n; ++i){
            if(isSafe[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
