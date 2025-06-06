class Solution {
public:
    int n;

    bool isPalindrome(int i, int j, string& s) {
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, string& s, vector<int>& dp){
        if(i == n) return -1;  // no cut needed beyond end
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int k = i; k < n; ++k){
            if(isPalindrome(i, k, s)){
                int cost = 1 + solve(k+1, s, dp);
                mini = min(mini, cost);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);
    }
};

