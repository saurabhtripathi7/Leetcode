class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuyPrice = prices[0];
        for(int i = 0; i < prices.size(); ++i){
            maxProfit = max(maxProfit, prices[i]-minBuyPrice);
            minBuyPrice = min(minBuyPrice, prices[i]);            
        }
        return maxProfit;
    }
};