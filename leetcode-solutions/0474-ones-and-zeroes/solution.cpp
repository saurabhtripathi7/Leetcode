class Solution {
public:
    typedef pair<int,int> P;
    int dp[601][101][101];
    
    int solve(int idx, int currM, int currN, vector<P>& str, int m, int n) {
        if (idx >= str.size()) return 0;
        if (dp[idx][currM][currN] != -1) return dp[idx][currM][currN];
        
        int notTake = solve(idx + 1, currM, currN, str, m, n);
        int take = 0;
        
        if (currM + str[idx].first <= m && currN + str[idx].second <= n) {
            take = 1 + solve(idx + 1, currM + str[idx].first, currN + str[idx].second, str, m, n);
        }
        
        return dp[idx][currM][currN] = max(take, notTake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<P> str;
        for (string& s : strs) {
            int zeroCount = count(s.begin(), s.end(), '0');
            int oneCount = s.size() - zeroCount;
            str.push_back({zeroCount, oneCount});
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, str, m, n);
    }
};

