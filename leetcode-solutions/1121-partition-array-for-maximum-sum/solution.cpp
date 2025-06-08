class Solution {
public: 
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& arr, int k){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int ind = i; ind < min(i + k, n); ++ind){
            len++;
            maxi = max(maxi, arr[ind]);
            int sum = (len * maxi) + solve(ind + 1, arr, k);
            maxAns = max(maxAns, sum); 
        }
        return dp[i] = maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);
        return solve(0, arr, k);
    }
};

