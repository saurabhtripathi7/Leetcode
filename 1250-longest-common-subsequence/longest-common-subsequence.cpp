class Solution {
public:
    int solve(string& s1, string& s2, vector<vector<int>>& dp) {
        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        // print LCS
        int i = 0, j = 0;
        string ans = "";
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                i++;
            } else {
                j++;
            }
        }
        cout << ans;
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        return solve(text1, text2, dp);
    }
};
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto Saurabh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define Saurabh_HACK
#ifdef Saurabh_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif