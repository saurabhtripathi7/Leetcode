class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // tabulation from last row to first cell
        int n = triangle.size();
        int lastRowSize = triangle[n-1].size();
        vector<int>prev(lastRowSize);
        // copy Last Row (n-1)th in Prev
        for(int i = 0; i < lastRowSize; ++i){
            prev[i] = triangle[n-1][i];
        }

        for(int i = n-2; i >= 0; --i){
            vector<int>curr(triangle[i].size(), 0);
            for(int j = 0; j < triangle[i].size(); ++j){
                int first = prev[j];
                int second = prev[j+1];
                curr[j] = triangle[i][j] + min(first, second);
            }
            prev = curr;
        }
        return prev[0];        
    }
};