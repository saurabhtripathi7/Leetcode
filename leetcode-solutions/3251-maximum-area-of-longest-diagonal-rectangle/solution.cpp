class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxDiagSq = 0; 
        int maxArea = 0;

        for (auto &v : dimensions) {
            long long diagSq = 1LL * v[0] * v[0] + 1LL * v[1] * v[1];
            int area = v[0] * v[1];

            if (diagSq > maxDiagSq || (diagSq == maxDiagSq && area > maxArea)) {
                maxDiagSq = diagSq;
                maxArea = area;
            }
        }

        return maxArea;
    }
};

