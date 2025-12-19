class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }

    void reset(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        DSU dsu(n);
        dsu.unite(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<int> involved;

            // union all meetings at same time
            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                int x = meetings[j][0];
                int y = meetings[j][1];
                dsu.unite(x, y);
                involved.push_back(x);
                involved.push_back(y);
                j++;
            }

            int secretRoot = dsu.find(0);

            // rollback those not connected to secret
            for (int p : involved) {
                if (dsu.find(p) != secretRoot)
                    dsu.reset(p);
            }

            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(0))
                ans.push_back(i);
        }
        return ans;
    }
};

