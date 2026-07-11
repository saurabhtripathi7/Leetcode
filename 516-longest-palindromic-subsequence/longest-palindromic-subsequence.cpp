class Solution {
public:
    int LCS(string &s, string &t, vector<vector<int>>& dp){
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = t.size()-1; j >= 0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        return LCS(s, t, dp);
    }
};