class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalXOR = 0;
        int n = nums.size();
        
        // Iterate over all possible subsets
        for (int subset = 0; subset < (1 << n); ++subset) {
            int currentXOR = 0;
            // Calculate XOR for the current subset
            for (int i = 0; i < n; ++i) {
                if (subset & (1 << i)) {
                    currentXOR ^= nums[i];
                }
            }
            totalXOR += currentXOR;
        }
        return totalXOR;
    }
};

