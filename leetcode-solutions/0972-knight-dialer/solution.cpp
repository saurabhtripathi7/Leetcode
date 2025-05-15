class Solution {
public:
    const int MOD = 1e9 + 7;
    int size;
    int dfs(int currSize, int cell, vector<vector<int>> &adj, vector<vector<int>>& dp){
        if(currSize == size) return 1;

        if(dp[currSize][cell] != -1) return dp[currSize][cell]; 

        int ans = 0;
        for(auto nbr : adj[cell]){
            ans = (ans + dfs(currSize+1, nbr, adj, dp)) % MOD;
        }

        return dp[currSize][cell] = ans;

    }
    int knightDialer(int n) {
        size = n;
        vector<vector<int>> adj{
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        vector<vector<int>> dp(n+1, vector<int>(10, -1));
        int res = 0;
        for(int cell = 0; cell <= 9; ++cell){
            res = (res + dfs(1, cell, adj, dp)) % MOD;
        }
        return res;
    }
};
