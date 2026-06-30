class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0); // for dp[i-1]

        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0); // for dp[i]
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};