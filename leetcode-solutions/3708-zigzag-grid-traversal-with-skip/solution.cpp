class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res; // Renamed ans to res
        vector<int> rowTraversal; // Renamed temp to rowTraversal
        int n = grid.size();
        int m = grid[0].size();
        
        for (int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                for (int j = 0; j < m; j++) {
                    rowTraversal.push_back(grid[i][j]);
                }
            }
            else {
                for (int j = m - 1; j >= 0; j--) {
                    rowTraversal.push_back(grid[i][j]);
                }
            }
        }
        
        for (int j = 0; j < n * m; j += 2) {
            res.push_back(rowTraversal[j]); 
        }
        
        return res;
    }
};

