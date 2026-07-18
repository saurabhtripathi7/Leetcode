class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, string& s1, string& s2){
        if(i == s1.length()) return s2.size() - j;
        if(j == s2.length()) return s1.size() - i;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] =  solve(i+1, j+1, s1, s2);
        int insertCh = 1 + solve(i, j+1, s1, s2);
        int deleteCh = 1 + solve(i+1, j, s1, s2);
        int replaceCh = 1 + solve(i+1, j+1, s1, s2);
        
        return dp[i][j] = min({insertCh, deleteCh, replaceCh});
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};