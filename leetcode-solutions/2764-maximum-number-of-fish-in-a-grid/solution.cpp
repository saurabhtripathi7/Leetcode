class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis, int& cnt, int dr[], int dc[]){
        if(vis[r][c]) return;
        vis[r][c] = true;
        int rows = grid.size();
        int cols = grid[0].size();
        cnt = cnt + grid[r][c];

        for(int i = 0; i < 4; ++i){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] > 0){
                dfs(nr, nc, grid, vis, cnt, dr, dc);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        int maxFish = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] > 0 && !vis[i][j]){
                    int cnt = 0;
                    dfs(i,j, grid, vis, cnt, dr, dc);
                    maxFish = max(maxFish, cnt);
                }
            }
        }
        return maxFish;

    }
};
