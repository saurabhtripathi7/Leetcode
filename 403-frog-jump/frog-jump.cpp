class Solution {
public:
    unordered_map<int, int> indexMap;
    vector<vector<int>> dp;

    bool solve(int idx, int lastJump, vector<int>& stones) {
        int n = stones.size();
        if (idx == n - 1) return true;

        if (dp[idx][lastJump] != -1) return dp[idx][lastJump];

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump <= 0) continue;
            int nextStone = stones[idx] + jump;

            if (indexMap.count(nextStone)) {
                if (solve(indexMap[nextStone], jump, stones))
                    return dp[idx][lastJump] = true;
            }
        }
        return dp[idx][lastJump] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        for (int i = 0; i < n; ++i) {
            indexMap[stones[i]] = i;
        }
        dp.assign(n, vector<int>(n + 1, -1));
        return solve(1, 1, stones);
    }
};