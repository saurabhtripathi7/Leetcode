class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> vis(n, false);
        long long score = 0;
        int i = 0;

        while (i >= 0 && i < n && !vis[i]) {
            vis[i] = true;
            if (instructions[i] == "add") {
                score += values[i];
                i++;
            } else if (instructions[i] == "jump") {
                i += values[i];
            }
        }

        return score;
    }
};

