class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        
        for (auto& query : queries) {
            int l = query[0]; 
            int r = query[1]; 
            
            diff[l] += 1; 
            if (r + 1 < n) {
                diff[r + 1] -= 1; }
        }

        // Check if all values in the nums array can become zero
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i]; // Accumulate the diff values
            if (curr < nums[i]) {
                return false; // If curr is less than the nums value, return
                              // false
            }
        }

        return true; 
        
    }
};
