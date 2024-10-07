class Solution {
public:
    int func(vector<int>& nums, int k) {
        if (k < 0) return 0;  // If k is negative, return 0 since no subarray can have negative distinct elements
        
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mpp;
        
        while (r < nums.size()) {
            mpp[nums[r]]++;  // Add nums[r] to the window
            
            // Shrink the window if there are more than k distinct elements
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);  // Remove the element completely
                }
                l++;  // Move the left pointer to shrink the window
            }
            
            // Count the number of subarrays with at most k distinct elements
            cnt += r - l + 1;
            r++;  // Move the right pointer to expand the window
        }
        
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Count subarrays with exactly k distinct elements
        return func(nums, k) - func(nums, k - 1);
    }
};

