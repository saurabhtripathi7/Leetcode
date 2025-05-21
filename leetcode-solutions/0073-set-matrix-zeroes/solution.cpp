class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int,int>>zeros;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 0){
                    zeros.push_back({i, j});
                }
            }
        }
        for(auto pair: zeros){
            int x = pair.first;
            int y = pair.second;

            for(int i = 0; i < n; ++i){
                matrix[i][y] = 0;
            }
            for(int j = 0; j < m; ++j){
                matrix[x][j] = 0;
            }
        }
        return;
    }
};
