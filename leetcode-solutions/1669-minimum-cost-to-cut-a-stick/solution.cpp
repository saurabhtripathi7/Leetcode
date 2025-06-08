class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<int>& cuts){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int ind = i; ind <= j; ++ind){
            int cost = (cuts[j+1] - cuts[i-1]) + solve(i, ind-1, cuts) + solve(ind+1, j, cuts);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        dp.assign(c, vector<int>(c, -1));
        return solve(1, c - 2, cuts);
    }
};

