class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        const int INF = 1e9;
        
        // Distance array: dist[i][j] = min moves to reach (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INF));
        
        // Record portal positions
        unordered_map<char, vector<pair<int,int>>> portals;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char ch = matrix[i][j];
                if(ch >= 'A' && ch <= 'Z')
                    portals[ch].push_back({i,j});
            }
        }
        
        // Track which portals we've “used” so we only teleport once per letter
        unordered_set<char> used;
        
        // Directions for normal moves
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        // 0-1 BFS deque
        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.emplace_front(0,0);
        
        while(!dq.empty()){
            auto [i,j] = dq.front(); dq.pop_front();
            int d = dist[i][j];
            
            // Early exit if we reached the goal
            if(i == n-1 && j == m-1)
                return d;
            
            // —— Teleportation edges (weight = 0) ——
            char c = matrix[i][j];
            if(c >= 'A' && c <= 'Z' && !used.count(c)){
                for(auto& [ti,tj] : portals[c]){
                    if(d < dist[ti][tj]){
                        dist[ti][tj] = d;
                        dq.emplace_front(ti, tj);
                    }
                }
                used.insert(c);
            }
            
            // —— Normal adjacent moves (weight = 1) ——
            for(auto& dir : dirs){
                int ni = i + dir[0], nj = j + dir[1];
                if(ni<0||ni>=n||nj<0||nj>=m) continue;
                if(matrix[ni][nj] == '#')            continue;
                if(d + 1 < dist[ni][nj]){
                    dist[ni][nj] = d + 1;
                    dq.emplace_back(ni, nj);
                }
            }
        }
        
        return -1;  // unreachable
    }
};
/*
Portal jumps cost 0 moves, so we add them to the front of the deque to explore immediately.

Normal moves cost 1 move, so we add them to the back.

This ordering makes sure we always explore free teleports before paying a move.

It guarantees the shortest path even when portals and normal moves interleave, fixing tricky test cases.
*/
