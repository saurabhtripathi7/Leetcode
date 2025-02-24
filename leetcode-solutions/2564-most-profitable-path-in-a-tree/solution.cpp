class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        
        // Build the undirected tree
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // bobTime[node] will hold the time when Bob reaches node (if on his path to 0)
        // Otherwise, it remains INT_MAX.
        vector<int> bobTime(n, INT_MAX);
        
        // DFS from Bob's starting node to node 0 (unique path in a tree).
        // It returns true if node 0 is reached from the current node.
        function<bool(int, int, int)> dfsBob = [&](int node, int parent, int time) -> bool {
            if (node == 0) {
                bobTime[node] = time;
                return true;
            }
            for (int nbr : adj[node]) {
                if (nbr == parent)
                    continue;
                if (dfsBob(nbr, node, time + 1)) {
                    bobTime[node] = time;
                    return true;
                }
            }
            return false;
        };
        dfsBob(bob, -1, 0);
        
        int ans = INT_MIN;
        
        // DFS for Alice starting from node 0.
        // 'time' is the number of steps taken from node 0.
        // 'currProfit' accumulates the profit along the current path.
        function<void(int, int, int, int)> dfsAlice = [&](int node, int parent, int time, int currProfit) {
            // Decide the profit from this node based on who arrives first.
            int profitHere = 0;
            if (time < bobTime[node])
                profitHere = amount[node];         // Alice arrives before Bob.
            else if (time == bobTime[node])
                profitHere = amount[node] / 2;       // They arrive at the same time.
            else
                profitHere = 0;                      // Bob already took the money.
            currProfit += profitHere;
            
            bool isLeaf = true;
            for (int nbr : adj[node]) {
                if (nbr == parent)
                    continue;
                isLeaf = false;
                dfsAlice(nbr, node, time + 1, currProfit);
            }
            
            // If it's a leaf node, update the answer.
            if (isLeaf)
                ans = max(ans, currProfit);
        };
        dfsAlice(0, -1, 0, 0);
        
        return ans;
    }
};

