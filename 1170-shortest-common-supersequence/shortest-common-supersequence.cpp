class Solution {
public:
    // While iterating on the LCS table, append each char that your i or j skips
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // create LCS table
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        // Iterate the table to create string
        string ans = "";
        int i = 0, j = 0;
        while(i < n && j < m){
            if(str1[i] == str2[j]){
                ans += str1[i];
                i++;
                j++;
            }
            else if(dp[i+1][j] >= dp[i][j]){ // move ith ptr downwards
                ans += str1[i];
                i++;
            }
            else{
                ans += str2[j];
                j++;
            }
        }
        // add the rem char until both ptrs are not totally exhausted
        while(i < n){
            ans += str1[i];
            i++;
        }
        while(j < m){
            ans += str2[j];
            j++;
        }
        return ans;
    }
};