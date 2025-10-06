class Solution {
public:
    typedef pair<int, pair<int, int>> P;

    int swimInWater(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty())
        {
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == m - 1 && col == n - 1)
            {
                return t;
            }
            for (auto& dir : directions)
            {
                int nRow = row + dir.first;
                int nCol = col + dir.second;
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && !vis[nRow][nCol])
                {
                    int newTime = max(t, grid[nRow][nCol]);
                    pq.push({newTime, {nRow, nCol}});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return -1;
    }
};

