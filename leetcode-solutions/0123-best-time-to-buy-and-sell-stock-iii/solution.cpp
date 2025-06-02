class Solution {
public:
    int n;

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // dp[n][2][3] -> ind(0....n-1), state(0,1), maxCap (0,1,2)
        vector<vector<int>>after(2, vector<int>(3, 0));// after = dp[ind+1]
        vector<vector<int>>curr(2, vector<int>(3, 0)); // curr = dp[ind]

        //base case 1
        for(int ind = 0; ind < n; ++ind){
            for(int state = 0; state <= 1; ++state){
                after[state][0] = 0; // for cap = 0, ind and state can be anything, profit will be 0
            } // if no cap left, profit is 0
        }
        //base case 2
        for(int state = 0; state <= 1; ++state){
            for(int cap  = 0; cap <= 2; ++cap){
                after[state][cap] = 0; // beyond last day, profit is 0
            }
        }

        for(int ind = n-1; ind >= 0; --ind){
            for(int state = 0; state <= 1; ++state){
                for(int cap = 1; cap <= 2; ++cap){ //cap from 1 bcz 0 is already done is Base Case
                //also cap-1 will be negative for cap = 0
                    int profit = 0;

                    if (state) { // can buy
                        int buyToday = -prices[ind] + after[0][cap];
                        int skipToday = 0 + after[1][cap];
                        profit = max(buyToday, skipToday);
                    } else { // can sell
                        int sellToday = prices[ind] + after[1][cap-1]; //--cap when trnx completed
                        int skipToday = 0 + after[0][cap];
                        profit = max(sellToday, skipToday);
                    }

                    curr[state][cap] = profit;
                    after = curr;
                }
            }
        }


        return after[1][2];
    }
};

// Space Optimization 3d -> 2d DP
// replace dp[ind + 1][][] with "after[][]"
