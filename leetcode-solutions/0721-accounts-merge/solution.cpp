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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> mpp;

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) { // start j from 1 as 0 is the name not email
                string email = accounts[i][j];
                if (mpp.find(email) == mpp.end()) { // if email does not already exist in map
                    mpp[email] = i;  // map email -> index of person
                } else {
                    dsu.unionByRank(i, mpp[email]);
                }
            }
        }

        vector<vector<string>> merged(n);
        // Put all emails from mpp into a merged list
        for (auto pair : mpp) {
            string email = pair.first;
            int index = dsu.findParent(pair.second); // find the ultimate parent index
            merged[index].push_back(email);
        }

        // Now create a list of lists with names instead of index
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            if (merged[i].empty()) continue; // skip empty merged list

            sort(merged[i].begin(), merged[i].end()); // sort emails lexicographically
            vector<string> temp;
            temp.push_back(accounts[i][0]); // first store the name, then store the emails
            for (auto it : merged[i]) {
                temp.push_back(it); // push all emails to the account
            }
            ans.push_back(temp);  // store the merged account in ans
        }

        return ans;
    }
};

