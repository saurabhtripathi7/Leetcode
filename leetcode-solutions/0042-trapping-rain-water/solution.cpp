class Solution {
public:
    int trap(vector<int>& height) {
        // Initialize left and right pointers
        int l = 0;
        int r = height.size() - 1;

        // Variables to track maximum heights from left and right
        int lMax = 0, rMax = 0;

        // Variable to store total trapped water
        int totalWater = 0;

        // Loop until the two pointers meet
        while (l < r) {
            // If the left height is less than or equal to the right height
            if (height[l] <= height[r]) {
                // If the current height is greater than or equal to lMax
                if (height[l] >= lMax) {
                    // Update lMax to the current height
                    lMax = height[l];
                } else {
                    // Calculate trapped water and add it to total
                    totalWater += lMax - height[l];
                }
                // Move the left pointer to the right
                l++;
            } else {
                // If the right height is less than the left height
                if (height[r] >= rMax) {
                    // Update rMax to the current height
                    rMax = height[r];
                } else {
                    // Calculate trapped water and add it to total
                    totalWater += rMax - height[r];
                }
                // Move the right pointer to the left
                r--;
            }
        }
        // Return the total amount of trapped water
        return totalWater;
    }
};

