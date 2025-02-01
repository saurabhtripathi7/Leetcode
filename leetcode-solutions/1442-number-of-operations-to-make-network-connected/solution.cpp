class DSU {
public:
    vector<int> parent, rank;

    DSU(int V) {
        parent.resize(V);
        rank.resize(V, 0);
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionByRank(int x, int y) {
        int xParent = findParent(x);
        int yParent = findParent(y);

        if (xParent == yParent) return;

        if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        }
        else if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        }
        else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extraEdges = 0;
        for(auto& e : connections){
            int u = e[0], v = e[1];
            if(dsu.findParent(u) == dsu.findParent(v)){
                extraEdges++;
            }
            else{
                dsu.unionByRank(u,v);
            }
        }

        int cntCompo = 0;
        for(int i = 0; i < n; ++i){
            if(dsu.findParent(i) == i)
            cntCompo++;
        }

        int ans = cntCompo - 1;

        return extraEdges >= ans ? ans : -1;


    }
};
