class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int>mpp;
        int ans = 0;
        while(r < n){
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};