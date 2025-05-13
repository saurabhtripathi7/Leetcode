class Solution {
public:
    // ans = Total - 2 * S1
    // Minimize ans => Minimize abs(Total - 2 * S1)
    // So find the subset sum S1 closest to Total / 2

    int solve(int i, int currSum, int totalSum, vector<int>& stones, vector<vector<int>>& dp) {
        if (i == stones.size()) {
            return abs(totalSum - 2 * currSum);
        }
        
        if (dp[i][currSum] != -1) return dp[i][currSum];
        
        // Pick the current stone
        int pick = solve(i + 1, currSum + stones[i], totalSum, stones, dp);
        
        // Not pick the current stone
        int notPick = solve(i + 1, currSum, totalSum, stones, dp);
        
        return dp[i][currSum] = min(pick, notPick);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size(), vector<int>(totalSum + 1, -1));
        return solve(0, 0, totalSum, stones, dp);
    }
};

