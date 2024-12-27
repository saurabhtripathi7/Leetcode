class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int maxval = values[0];
        for(int i = 1;i<values.size();i++)
        {
            ans = max(ans,maxval+values[i]-i);
            maxval = max(maxval,values[i]+i);
        }
        return ans;
    }
};
