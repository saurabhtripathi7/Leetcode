class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        parent[px] = py;
        size[py] += size[px];
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    int m, n;

    int index(int r, int c) {
        return r * n + c;
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        m = grid.size();
        n = grid[0].size();
        int top = m * n;  // virtual top node
        vector<vector<int>> copy = grid;

        // Step 1: Apply all hits by removing bricks
        for (auto& hit : hits) {
            int r = hit[0], c = hit[1];
            if (copy[r][c] == 1) copy[r][c] = 0;
        }

        // Step 2: Build DSU from the modified grid
        DSU dsu(m * n + 1);

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (copy[r][c] == 1) {
                    int curr = index(r, c);
                    if (r == 0) {
                        dsu.unionSet(curr, top);  // connect top row to virtual top
                    }
                    for (auto& dir : dirs) {
                        int nr = r + dir[0], nc = c + dir[1];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n && copy[nr][nc] == 1) {
                            dsu.unionSet(curr, index(nr, nc));
                        }
                    }
                }
            }
        }

        // Step 3: Reverse process hits
        vector<int> res(hits.size());

        for (int i = hits.size() - 1; i >= 0; --i) {
            int r = hits[i][0], c = hits[i][1];

            if (grid[r][c] == 0) {
                res[i] = 0;
                continue;
            }

            int before = dsu.getSize(top);  // old size

            int pos = index(r, c);
            //restore the brick
            copy[r][c] = 1;

            // If it's on the top row, connect to virtual top
            if (r == 0) {
                dsu.unionSet(pos, top);
            }

            for (auto& dir : dirs) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && copy[nr][nc] == 1) {
                    dsu.unionSet(pos, index(nr, nc));
                }
            }

            int after = dsu.getSize(top);  // new size

            res[i] = max(0, after - before - 1);  // exclude the restored brick
        }

        return res;
    }
};

