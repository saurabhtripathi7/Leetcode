class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int iMax = nums[0]; //for max element
        int maxIndex = 0;   // for index of max element
        for(int i = 1; i<nums.size();++i){
            if(nums[i] > iMax){
                iMax = nums[i];
                maxIndex  = i;
            }
        }
        int maxLen = 0;
        // Traverse from maxIndex on
        for(int i = maxIndex; i < nums.size(); ++i){
            int len = 0;
            // find contiguous subarray with iMax value
            while(i < nums.size() && nums[i] == iMax){
                i++;
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
