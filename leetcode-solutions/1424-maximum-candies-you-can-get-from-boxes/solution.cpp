class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<int> visited(n, 0);       // Whether a box has been opened and processed
        vector<int> foundBoxes(n, 0);    // Whether we physically have this box
        queue<int> q;

        for (int box : initialBoxes) {
            foundBoxes[box] = 1;
            if (status[box] == 1) {
                visited[box] = 1;
                q.push(box);
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            totalCandies += candies[curr];
            candies[curr] = 0;

            // Collect keys and unlock boxes
            for (int key : keys[curr]) {
                if (status[key] == 0) {
                    status[key] = 1;
                    if (foundBoxes[key] && !visited[key]) {
                        visited[key] = 1;
                        q.push(key);
                    }
                }
            }

            // Add contained boxes
            for (int b : containedBoxes[curr]) {
                foundBoxes[b] = 1;
                if (status[b] == 1 && !visited[b]) {
                    visited[b] = 1;
                    q.push(b);
                }
            }
        }

        return totalCandies;
    }
};

