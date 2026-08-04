class Solution {
public:
    // returns count of subarray having <=K unique elements
    int slidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, count = 0;
        unordered_map<int, int> mpp;

        while(r < n){
            mpp[nums[r]]++;
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);  
                }
                l++;  
            }
            count += (r-l+1);
            r++;            
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
};