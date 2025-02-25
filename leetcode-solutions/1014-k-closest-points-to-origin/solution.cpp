class Solution {
public:
    static bool cmp(vector<int>& A, vector<int>& B) {
        return (A[0] * A[0] + A[1] * A[1]) < (B[0] * B[0] + B[1] * B[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

