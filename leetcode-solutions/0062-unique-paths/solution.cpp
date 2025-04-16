class Solution {
public:
    /*
    Space Optimization (2D --> 1D):
    NOTE: If ans of current state depend of prev few states(here 2, up and
    left), then we can Space Opt tabulation

    Answer of current state depend on left and up block, dp[i][j] = dp[i-1][j] +
    dp[i][j-1] If we take a prev[n] = {all 0} and take a temp[n] for computing
    temp[j] =  temp[j-1] (left) + prev[j] (up)

    */
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0); // take a dummy top col with all 0 init
        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if(i == 0 && j == 0) {
                    curr[j] = 1;
                    continue;
                }
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j-1] : 0;
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};
/*
TABULATION Steps:
1. Fill table with base cases
2. Express all rec states as for loops (if 2 variables change, use 2 nested for
loops)
3. Copy recurrence and write
here, i -- > m-1 and j -- > n-1
*/
