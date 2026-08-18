class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMin = nums[0], currMax = nums[0], ans = nums[0];

        for(int i = 1; i < n; ++i){
            int prevMax = currMax;
            int prevMin = currMin;
            currMax = max({nums[i], prevMax*nums[i], prevMin*nums[i]});
            currMin = min({nums[i], prevMax*nums[i], prevMin*nums[i]});
            ans = max(ans, currMax);
        }
        return ans;
    }
};