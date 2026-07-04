class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }

    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unite(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        if(px == py) return;

        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else{
            parent[py] = px;
            rank[px]++;
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);
        for(auto &e : roads){
            dsu.unite(e[0], e[1]);
        }
        int root = dsu.findParent(1);
        int ans = INT_MAX;
        for(auto &e : roads){
            int u = e[0], v = e[1], w = e[2];
            if(dsu.findParent(e[0]) == root) ans = min(ans, w); 
        }
        return ans;
    }
};