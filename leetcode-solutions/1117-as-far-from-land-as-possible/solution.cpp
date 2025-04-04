class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cntZeros = 0;
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(grid[i][j] == 1){
                    q.push({0, {i, j}});
                    grid[i][j] = 7; //for vis
                }
                else{
                    cntZeros++;
                }
            }
        }
        if(cntZeros == 0) return -1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int finalDist = -1;

        while(!q.empty()){
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            finalDist = max(finalDist, dist);

            for(int i = 0; i < 4; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != 7 
                && grid[nr][nc] == 0){
                    q.push({dist+1, {nr, nc}});
                    grid[nr][nc] = 7;
                }
            }
        }

        return finalDist;

        

    }
};
