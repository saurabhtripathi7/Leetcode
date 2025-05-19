class Solution {
public:
    int LCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + LCS(i-1, j-1, s1, s2, dp);
        }
        
        return dp[i][j] = 0 + max(LCS(i-1, j, s1, s2, dp), LCS(i, j-1, s1, s2, dp));
        
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        int m = n;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return (LCS(n-1, m-1, s, s2, dp));  //LPS = LCS(s, s.reverse);
    }

    //  No of insertions = No. of Deletion = s.length() - LPS
    int minInsertions(string s) {
        int ans = s.length() - longestPalindromeSubseq(s);
        return ans;
    }
};
