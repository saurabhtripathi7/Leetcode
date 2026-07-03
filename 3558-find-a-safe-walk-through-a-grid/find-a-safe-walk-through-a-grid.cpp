class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>>dq;
        dq.emplace_front(0,0); // emplace directly constructs pair obj with passed arguments in deque (no pair creation then copying into deque)

        dist[0][0] = grid[0][0];

        static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!dq.empty()){
            auto [r, c] = dq.front();
            dq.pop_front();

            if(r == m-1 && c == n-1) return true; // bcz of pruing invalid states before enqueuing them

            for(auto& [dr, dc] : DIRS){
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

                int cost = dist[r][c] + grid[nr][nc]; // cost to reach new cell = cost of reaching curr cell + new cell's value
                if(cost >= health) continue; // prune invalid states

                if(cost < dist[nr][nc]){
                    dist[nr][nc] = cost;
                    if(grid[nr][nc] == 0) dq.emplace_front(nr, nc);
                    else dq.emplace_back(nr, nc);
                }
            }
        }
        return false;
    }
};