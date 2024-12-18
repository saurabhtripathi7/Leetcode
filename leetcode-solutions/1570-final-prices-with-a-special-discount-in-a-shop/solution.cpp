class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);

        for (int i = n - 1; i >= 0; --i) {
            result[i] = prices[i]; // Initialize with original price
            for (int j = i + 1; j < n; ++j) { // Look for discount
                if (prices[j] <= prices[i]) {
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }

        return result;
    }
};

