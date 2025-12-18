class Solution {
public:
// currentProfit = totalOriginalProfit − originalProfit(of the chosen k-length window) + newProfit(after modifying that k-length window)

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> preSum(n), preProdSum(n);
        preSum[0] = prices[0];
        preProdSum[0] = 1LL * prices[0] * strategy[0];

        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + prices[i];
            preProdSum[i] = preProdSum[i - 1] + 1LL * prices[i] * strategy[i];
        }

        long long totalOrgProfit = preProdSum[n - 1];

        long long ans = totalOrgProfit;

        for (int l = 0; l + k - 1 < n; l++) {
            int r = l + k - 1;
            int mid = l + k / 2;

            long long orgProfK =
                preProdSum[r] - (l > 0 ? preProdSum[l - 1] : 0);

            long long newProfK =
                preSum[r] - (mid > 0 ? preSum[mid - 1] : 0);

            long long currProfit = totalOrgProfit - orgProfK + newProfK;
            ans = max(ans, currProfit);
        }

        return ans;
    }
};

