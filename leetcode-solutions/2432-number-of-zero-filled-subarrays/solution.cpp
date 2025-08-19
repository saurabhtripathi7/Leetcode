class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] != 0) {
                l = r + 1; // reset window start
            } else {
                ans += (r - l + 1); // all subarrays ending at r
            }
        }
        return ans;
    }
};

