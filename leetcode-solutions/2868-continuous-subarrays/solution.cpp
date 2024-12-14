class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long cnt = 0;
        int n = nums.size();
        map<int, int> mpp;
        int l = 0, r = 0;

        while (r < n){
            mpp[nums[r]]++;

            // Shrink the window if the difference between the max and min exceeds 2
            while (abs(mpp.rbegin()->first - mpp.begin()->first) > 2) {
                // Shrink the window from the left
                mpp[nums[l]] -= 1;
                if (mpp[nums[l]] == 0) {
                    mpp.erase(nums[l]);
                }
                l++;  // Only increment l to shrink the window
            }

            // Increment the count by the number of valid subarrays
            cnt += r - l + 1;
            r++;  // Move the right pointer forward
        }
        return cnt;
    }
};

