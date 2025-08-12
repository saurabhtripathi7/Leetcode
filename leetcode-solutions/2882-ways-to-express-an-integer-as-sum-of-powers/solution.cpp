#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    // Compute i^x safely as long long
    long long iPow(int base, int exp) {
        long long res = 1;
        for (int i = 0; i < exp; ++i) {
            res *= base;
            if (res > 1e9) break; // optional pruning
        }
        return res;
    }

    int numberOfWays(int n, int x) {
        // Find max base i such that i^x <= n
        int maxBase = 1;
        while (iPow(maxBase, x) <= n) maxBase++;

        // dp[i][rem]: number of ways to form 'rem' using bases >= i
        vector<vector<int>> dp(maxBase + 1, vector<int>(n + 1, 0));

        // Base case: 1 way to form sum 0
        for (int i = 0; i <= maxBase; ++i) {
            dp[i][0] = 1;
        }

        // Fill the table bottom-up
        for (int i = maxBase - 1; i >= 1; --i) {
            long long powerVal = iPow(i, x);
            for (int rem = 0; rem <= n; ++rem) {
                int waysSkip = dp[i + 1][rem];
                int waysPick = 0;
                if (powerVal <= rem)
                    waysPick = dp[i + 1][rem - powerVal];

                dp[i][rem] = (waysPick + waysSkip) % MOD;
            }
        }

        // Result: ways to form sum n starting from 1
        return dp[1][n];
    }
};

