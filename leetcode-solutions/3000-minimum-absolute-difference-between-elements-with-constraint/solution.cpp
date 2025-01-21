class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int minDiff = INT_MAX;
        set<int>st;
        for(int i = x; i < nums.size(); ++i){
            int prev = nums[i-x];
            int curr = nums[i];
            st.insert(prev);
            auto lb = st.lower_bound(curr);
            if(lb != st.end()){
                minDiff = min(minDiff, abs(curr - *(lb)));
            }
            if(lb != st.begin()){
                lb--;
                minDiff = min(minDiff, abs(curr - *(lb)));
            }
        }
        return minDiff;
    }
};
