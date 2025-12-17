class Solution {
public:
    long long maximumProfit(vector<int>& prices, int K) {
        int n = prices.size();

        long long t[1001][501][3];

        // Base case: i == n
        for (int k = 0; k <= K; k++) {
            t[n][k][0] = 0;
            t[n][k][1] = INT_MIN;
            t[n][k][2] = INT_MIN;
        }

        // Fill table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= K; k++) {

                // Don't take any action
                t[i][k][0] = t[i + 1][k][0];

                // Take action
                //  CASE 0: no transaction in progress
                if (k > 0) {
                    t[i][k][0] =
                        max(t[i][k][0],
                            max(-prices[i] + t[i + 1][k][1], // buy
                                prices[i] + t[i + 1][k][2]   // short sell
                                ));
                }

                // CASE 1: holding long
                t[i][k][1] = t[i + 1][k][1]; // hold
                if (k > 0) {
                    t[i][k][1] = max(t[i][k][1],
                                     prices[i] + t[i + 1][k - 1][0] // sell
                    );
                }

                // CASE 2: holding short
                t[i][k][2] = t[i + 1][k][2]; // hold
                if (k > 0) {
                    t[i][k][2] = max(t[i][k][2],
                                     -prices[i] + t[i + 1][k - 1][0] // buy back
                    );
                }
            }
        }

        // Start from day 0, k transactions, no open position
        return t[0][K][0];
    }
};
