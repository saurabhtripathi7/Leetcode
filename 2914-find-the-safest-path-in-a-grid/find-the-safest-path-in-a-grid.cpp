class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        // MS BFS for finding safeness factor (nearest theif from every cell)
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [r,c] = q.front();
                q.pop();

                distNearestThief[r][c] = level;

                for(auto &d: directions){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr>=0 && nc>=0 && nr<n && nc<n && !visited[nr][nc]){
                        visited[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
            level++;
        }

        // BS on Ans for max safeness factor
        int l = 0;
        int r = 2*n;
        int result = 0;

        while(l <= r){
            int mid_sf = l + (r-l)/2;
            if(check(distNearestThief, mid_sf) == true) {
                result = mid_sf;
                l = mid_sf+1; // try to maximize
            } else {
                r = mid_sf-1;
            }
        }
        return result;
    }
private:
    bool check(vector<vector<int>>& distNearestThief, int sf) {
        queue<pair<int, int>> que;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        //0,0 --> n-1, n-1
        que.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf)
            return false;

        while(!que.empty()) {
            int curr_i = que.front().first;
            int curr_j = que.front().second;

            que.pop();

            if(curr_i == n-1 && curr_j == n-1) {
                return true;
            }

            for(vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];

                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true) {
                    if(distNearestThief[new_i][new_j] < sf) {
                        continue; //reject this cell
                    }
                    que.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }

            }
        }
        return false;
    }
}; // O(n^2) * log(n)