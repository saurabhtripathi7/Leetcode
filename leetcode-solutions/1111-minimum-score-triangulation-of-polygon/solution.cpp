class Solution {
public:
    int dp[51][51];
    int solve(vector<int>&values, int i, int j){
        if((j-i+1)<3)
        return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int result = INT_MAX;
        for(int k = i+1;k<j;k++){
            int weight = solve(values,i,k) +  values[i] * values[k] * values[j] + solve(values,k,j);
            result = min(result,weight);
        }

        return dp[i][j] = result;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp,-1,sizeof(dp));
        return solve(values,0,n-1);
    }
};
