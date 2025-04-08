class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if (st.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {
            string curr = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (curr == target) return lvl;

            for (int i = 0; i < 4; ++i) {
                char org = curr[i];

                // move one step forward
                curr[i] = (org - '0' + 1) % 10 + '0';
                if (!st.count(curr) && !vis.count(curr)) {
                    vis.insert(curr);
                    q.push({curr, lvl + 1});
                }

                // move one step backward
                curr[i] = (org - '0' + 9) % 10 + '0'; 
                if (!st.count(curr) && !vis.count(curr)) {
                    vis.insert(curr);
                    q.push({curr, lvl + 1});
                }

                curr[i] = org;
            }
        }

        return -1;
    }
};

