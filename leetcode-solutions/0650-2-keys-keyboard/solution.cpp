class Solution {
public:
    static const int INF = 1e9;
    int dp[1001][1001]; // assuming n <= 1000

    int solve(int currSum, int buffer, int n) {
        if (currSum > n) return INF;      // prune
        if (currSum == n) return 0;       // done
        if (dp[currSum][buffer] != -1) return dp[currSum][buffer];

        int best = INF;

        if (buffer > 0) {
            best = min(best,
                       1 + solve(currSum + buffer, buffer, n));
        }

        // Copy All (only if buffer != currSum, i.e. it actually changes buffer)
        if (buffer != currSum) {
            best = min(best,
                       1 + solve(currSum, currSum, n));
        }

        return dp[currSum][buffer] = best;
    }

    int minSteps(int n) {
        if (n <= 1) return 0;
        memset(dp, -1, sizeof(dp));
        return solve(1, 0, n);  // start with 1 'A' on screen, empty buffer
    }
};

