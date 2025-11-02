class Solution {
public:

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>>grid(m,vector<char>(n,'.'));
        vector<vector<bool>>canSee(m,vector<bool>(n,false));
        for(int i = 0;i<guards.size();i++){
            int r = guards[i][0];
            int c = guards[i][1];
            grid[r][c] = 'G';
        }
        for(int i = 0;i<walls.size();i++){
            int r = walls[i][0];
            int c = walls[i][1];
            grid[r][c] = 'W';
            
        }
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &g : guards){
            int r = g[0];
            int c = g[1];
            for(auto &dir:dirs){
                int dr = dir.first;
                int dc = dir.second;

                int nr = r + dr;
                int nc = c + dc;
                while(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]!='W' && grid[nr][nc]!='G'){
                    canSee[nr][nc] = true;
                    nr += dr;
                    nc += dc;
                }
            }

        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.' && !canSee[i][j])
                    count++;
            }
        }

        return count;
    }
};
