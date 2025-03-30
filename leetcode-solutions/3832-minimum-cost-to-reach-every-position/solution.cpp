class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> ans(n, 0);
        
        ans[0] = cost[0];
        int minCost = cost[0];
        
        for (int i = 1; i < n; ++i) {
            minCost = min(minCost, cost[i]);
            ans[i] = minCost;
        }
        
        return ans;
    }
};

