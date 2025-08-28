class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, deque<int>> mpp;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mpp[i - j].push_back(grid[i][j]);
            }
        }

        for (auto &it : mpp) {
            if (it.first < 0) {
                sort(it.second.begin(), it.second.end());
            } else {
                sort(it.second.begin(), it.second.end(), greater<int>());
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = mpp[i - j].front();
                mpp[i - j].pop_front();
            }
        }

        return ans;
    }
};
