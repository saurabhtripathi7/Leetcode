class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int M = s1.length();
        int N = s2.length();
        //dp[m][n] = SCS upto str s1 and s2 of len m, n
        vector<vector<int>>dp(M+1, vector<int>(N+1, 0));
        //i, j -> current last char of s1, s2 
        for(int i = 0; i <= M; ++i){
            for(int j = 0; j <= N; ++j){
                if(i == 0 || j == 0){
                    dp[i][j] = i+j; //rem no of char of non zero str
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string res = "";
        int i = M, j = N;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){ // cmp last chars
                res.push_back(s1[i-1]);
                i--;
                j--;                
            }
            else if(dp[i-1][j] < dp[i][j-1]){
                res.push_back(s1[i-1]);
                i--;
            }
            else{
                res.push_back(s2[j-1]);
                j--;
            }
        }

        while(i > 0){
            res.push_back(s1[i-1]);
            i--;
        }
        while(j > 0){
            res.push_back(s2[j-1]);
            j--;
        }

        reverse(res.begin(), res.end());

        return res;

    }
};
