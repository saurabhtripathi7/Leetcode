class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // map Key (i+j) -> vector of same values
        map<int, vector<int>> mpp;

        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        // reverse the alt vectors and store in result
        bool flip = true;
        for (auto& it : mpp) {
            if (flip) {
                reverse(it.second.begin(), it.second.end());
            }
            for (auto x : it.second) {
                res.push_back(x);
            }
            flip = !flip;
        }

        return res;
    }
};
