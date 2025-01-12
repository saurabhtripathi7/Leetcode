class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int rows = coins.size();
        int cols = coins[0].size();

        // DP table: dp[i][j][k] represents the maximum profit at (i, j) with k
        // robbers neutralized
        vector<vector<vector<int>>> dp(
            rows, vector<vector<int>>(cols, vector<int>(3, INT_MIN)));

        // Base case
        for (int k = 0; k < 3; k++) {
            dp[0][0][k] = coins[0][0] < 0 && k > 0 ? 0 : coins[0][0];
        }

        // Fill the DP table
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i == 0 && j == 0)
                        continue; // Skip starting cell

                    int maxWithoutNeutralizing = INT_MIN;
                    int maxWithNeutralizing = INT_MIN;

                    // Transition from top
                    if (i > 0) {
                        maxWithoutNeutralizing =
                            max(maxWithoutNeutralizing, dp[i - 1][j][k]);
                        if (k > 0 && coins[i][j] < 0) {
                            maxWithNeutralizing =
                                max(maxWithNeutralizing, dp[i - 1][j][k - 1]);
                        }
                    }

                    // Transition from left
                    if (j > 0) {
                        maxWithoutNeutralizing =
                            max(maxWithoutNeutralizing, dp[i][j - 1][k]);
                        if (k > 0 && coins[i][j] < 0) {
                            maxWithNeutralizing =
                                max(maxWithNeutralizing, dp[i][j - 1][k - 1]);
                        }
                    }

                    // Update DP state
                    if (coins[i][j] < 0) {
                        dp[i][j][k] = max(maxWithoutNeutralizing + coins[i][j],
                                          maxWithNeutralizing);
                    } else {
                        dp[i][j][k] = maxWithoutNeutralizing + coins[i][j];
                    }
                }
            }
        }

        // Find the maximum profit at the bottom-right corner
        return max({dp[rows - 1][cols - 1][0], dp[rows - 1][cols - 1][1],
                    dp[rows - 1][cols - 1][2]});
    }
};
