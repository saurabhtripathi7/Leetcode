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

    void Union(int x, int y) {
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
    int n, m;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int getIndex(int i, int j){
        return i*m+j;
    }
    bool inBounds(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row*col + 2 ); //2 extra for top and bottom

        
        n = row;
        m = col;
        vector<vector<int>>copy(n, vector<int>(m, 1)); // 1 means water initially

        int top = n*m;
        int bottom = n*m+1;


        for(int i = (n*m)-1; i >= 0; --i){
            int r = cells[i][0] - 1, c = cells[i][1] - 1;

            //restore land cell
            copy[r][c] = 0; // 0 -> land, 1 -> water

            if(r == 0){
                dsu.Union(top, getIndex(r,c));
            }
            if(r == n-1){
                dsu.Union(bottom, getIndex(r,c));
            }

            for(int j = 0; j < 4; ++j){
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(inBounds(nr, nc) && copy[nr][nc] == 0){
                    dsu.Union(getIndex(r,c), getIndex(nr, nc));
                }
            }
            
            if(dsu.find(top) == dsu.find(bottom)){
                return i;
            }
        }
        return 0;

    }
};
