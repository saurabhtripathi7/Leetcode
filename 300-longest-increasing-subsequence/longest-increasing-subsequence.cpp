class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>sortedAsc;

        for(int i = 0; i < n; ++i){
            auto iterator = lower_bound(sortedAsc.begin(), sortedAsc.end(), nums[i]);

            if(iterator == sortedAsc.end()) sortedAsc.push_back(nums[i]);
            else *iterator = nums[i];
        }
        return sortedAsc.size();
    }
};