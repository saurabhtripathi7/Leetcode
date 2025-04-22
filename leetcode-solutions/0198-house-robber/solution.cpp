class Solution {
public:
    // Tabulation
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; ++i){
            int pick = nums[i] + prev2;
            int skip = prev1;
            int currMaxSum = max(pick, skip);
            prev2 = prev1;
            prev1 = currMaxSum;
        }
        return prev1;
    }
};
