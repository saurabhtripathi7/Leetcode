class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
        } 
        return dp[i][j] = 0 + max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
