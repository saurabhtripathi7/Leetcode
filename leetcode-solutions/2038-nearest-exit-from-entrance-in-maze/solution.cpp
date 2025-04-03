class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            int currDist = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && 
                !(row == entrance[0] && col == entrance[1])) {
                return currDist;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = row + delRow[i];
                int nc = col + delCol[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                    maze[nr][nc] = '+';  
                    q.push({currDist + 1, {nr, nc}});
                }
            }
        }

        return -1; 
    }
};

