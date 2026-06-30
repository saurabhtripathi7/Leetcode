class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>prev(n, 0);        

        // Initialize first row (i=0)
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            prev[j] = 1;
        }

        for(int i = 1; i < m; ++i){
            vector<int>curr(n, 0);
            for(int j = 0; j < n; ++j){
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else{
                    int left = (j > 0) ? curr[j-1] : 0;
                    int up = prev[j];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};