#pragma GCC optimize('O3,unroll-loops')
#pragma GCC target('avx2,bmi,bmi2,lzcnt,popcnt')
static const bool __boost = []()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  return std::ios_base::sync_with_stdio(false);
}();

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i = 0; i < mat.size(); ++i){
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            minHeap.push({sum, i});
        }
        vector<int>res;
        for (int i = 0; i < k; ++i) {
            if (!minHeap.empty()) {
                auto topPair = minHeap.top();
                minHeap.pop();
                res.push_back(topPair.second);
            }
        }
        return res;
    }
};
