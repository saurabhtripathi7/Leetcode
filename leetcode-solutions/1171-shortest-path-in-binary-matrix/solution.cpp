class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>>q; //{dist, {row, col}}
        int rows = grid.size();
        int cols = grid[0].size();

        // If the start or end cell is blocked
        if (grid[0][0] != 0 || grid[rows - 1][cols - 1] != 0) return -1;
         // If the grid contains only one cell and it's unblocked
        if (rows == 1 && cols == 1) return 1;
        
        vector<vector<int>>dist(rows, vector<int>(cols, INT_MAX));
        q.push({1, {0, 0}});
        
        while(!q.empty()){
            auto [dis, rc] = q.front(); q.pop();// Decompose the outer pair
            auto [r, c] = rc;          // Decompose the inner pair

            for(int dr = -1; dr <= 1; ++dr){
                for(int dc = -1; dc <= 1; dc++){
                    int nr = r + dr;
                    int nc = c + dc;

                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 0 && 
                    dis+1 < dist[nr][nc]){
                        dist[nr][nc] = 1+dis;
                        if(nr == rows-1 && nc == cols-1) return 1+dis;
                        q.push({1+dis, {nr, nc}}); 
                    }
                }
            }

        }
        return -1;

    }
};
