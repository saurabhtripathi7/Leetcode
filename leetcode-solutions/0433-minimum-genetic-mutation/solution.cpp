class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(end) == bankSet.end()) return -1; 

        queue<string> q;
        unordered_set<string> visited;
        vector<char> chars = {'A', 'C', 'G', 'T'};

        q.push(start);
        visited.insert(start);
        int level = 0;

        while (!q.empty()) {
            int size = q.size(); // Process all strings at the current BFS level
            for (int s = 0; s < size; ++s) {
                string curr = q.front();
                q.pop();

                if (curr == end) return level;

                for (int i = 0; i < curr.size(); ++i) {
                    char original = curr[i];

                    for (char ch : chars) {
                        if (ch == original) continue; // Skip if same char

                        curr[i] = ch;

                        if (bankSet.find(curr) != bankSet.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[i] = original; // Restore
                }
            }
            level++; // Increment level **after processing all elements at this BFS level**
        }
        return -1;
    }
};

