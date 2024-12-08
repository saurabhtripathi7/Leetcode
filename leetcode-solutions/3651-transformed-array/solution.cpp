class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i) {
            int steps = nums[i];
            if (steps > 0) {
                int destination = (i + steps) % n;
                result[i] = nums[destination];
            } else if (steps < 0) {
                // Adjust for negative steps properly
                int destination = (i + steps) % n;
                // If the result of (i + steps) is negative, add n to ensure it's within bounds
                if (destination < 0) {
                    destination += n;
                }
                result[i] = nums[destination];
            } else {
                result[i] = nums[i];
            }
        }
        
        return result;
    }
};

