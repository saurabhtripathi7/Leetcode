class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;  // To store the maximum length of a valid subarray
        int l = 0;       // Left pointer for the sliding window
        int r = 0;       // Right pointer for the sliding window
        int zeros = 0;   // To keep track of the number of zeros in the current window
        
        // Traverse through the array with the right pointer
        while (r < nums.size()) {
            
            // If the current element is 0, increment the zeros count
            if (nums[r] == 0)  
                zeros++;

            // If the number of zeros exceeds k, adjust the left pointer to reduce the window
            if (zeros > k) {
                // If the element at the left pointer is 0, we decrement the zeros count
                if (nums[l] == 0) {
                    zeros--;
                }
                // Move the left pointer to shrink the window
                l++;
            }

            // Calculate the current window length and update the maximum length
            maxLen = max(maxLen, r - l + 1);
            
            // Move the right pointer to expand the window
            r++;
        }
        
        // Return the maximum length of the subarray with at most k zeros
        return maxLen;
    }
};

