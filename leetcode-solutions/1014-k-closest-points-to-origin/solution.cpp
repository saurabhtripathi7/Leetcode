class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int, pair<int, int>>> maxH;
        for(int i = 0; i < points.size(); ++i){
            int x = points[i][0];
            int y = points[i][1];
            int D = pow(x, 2) + pow(y, 2);
            maxH.push({D, {x,y}});

            if(maxH.size() > k){
                maxH.pop();
            }
        }

        while(!maxH.empty()) {
            res.push_back({maxH.top().second.first, maxH.top().second.second});
            maxH.pop();
        }

        return res;
    }
};

static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
