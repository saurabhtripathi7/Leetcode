class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int l = 0, r = 0;
        int zeros = 0, ones = 0;
        while(r < nums.size()){
            if(nums[r] == 0) zeros++;

            while(zeros > 1){
                if(nums[l] == 0) zeros--;
                l++;
            }
            maxLen = max(maxLen, r-l);
            r++;
        }
        return maxLen;
    }
};
