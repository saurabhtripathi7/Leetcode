class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findParent(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findParent(parent[i]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV)
            return;

        if (size[rootU] < size[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        //firstly do union of all == cases
        for( const auto &s : equations){
            if(s[1] == '='){
                dsu.unionBySize(s[0]-'a', s[3]-'a');
            }
        } 
        //find != cases and check satisfiablity
        for( const auto &s : equations){
            if(s[1] == '!'){
                int first = s[0]-'a';
                int second = s[3]-'a';

                int parent1st = dsu.findParent(first);
                int parent2nd = dsu.findParent(second);

                if(parent1st == parent2nd) return false;

            }
        }
        return true;
    }
};
