class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int >h1 = heights;
        // for(int i = 0; i < heights.size(); ++i){
        //     h1.push_back(heights[i]);
        // }
        sort(h1.begin(), h1.end());
        int cnt = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(h1[i] != heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
