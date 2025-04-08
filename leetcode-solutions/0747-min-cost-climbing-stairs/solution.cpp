class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        if (i >= cost.size()) return 0; // 0 cost after nth idx
        if (dp[i] != -1) return dp[i];

        int step1 = solve(i + 1, cost, dp);
        int step2 = solve(i + 2, cost, dp);

        return dp[i] = cost[i] + min(step1, step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1); 

        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};

