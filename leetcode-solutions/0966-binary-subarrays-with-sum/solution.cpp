class Solution {
public:
    // Helper function to count subarrays with sum <= 'goal'.
    int func(vector<int>& nums, int goal){
        // Step 1: If the goal is negative, there can't be any subarrays with such a sum.
        if(goal < 0) return 0;

        // Step 2: Initialize the sliding window pointers 'l' (left) and 'r' (right), 
        // a variable 'sum' to store the current window sum, 
        // and 'cnt' to keep track of the number of valid subarrays.
        int l = 0, r = 0, sum = 0, cnt = 0;

        // Step 3: Iterate through the array with the right pointer 'r'.
        while(r < nums.size()){
            // Step 4: Add the current element to 'sum' to maintain the sum of the current window.
            sum += nums[r];

            // Step 5: If the sum of the current window exceeds the 'goal', 
            // move the left pointer 'l' to reduce the window size and bring 'sum' back within the goal.
            while(sum > goal){
                sum -= nums[l];  // Subtract the element at 'l' from the sum.
                l++;             // Move the left pointer forward.
            }

            // Step 6: Add the number of subarrays ending at 'r' and starting from 'l' or earlier.
            // The number of subarrays added here is (r - l + 1) because the subarray can start 
            // anywhere from 'l' to 'r' and end at 'r'.
            cnt += r - l + 1;

            // Step 7: Move the right pointer forward to check the next element.
            r++;
        }

        // Step 8: Return the total count of subarrays with sum <= 'goal'.
        return cnt;
    }

    // Function to count the number of subarrays with an exact sum equal to 'goal'.
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Step 9: Use the helper function 'func' to count the subarrays with sum <= 'goal'.
        // Subtract the result of 'func' with 'goal-1' from the result with 'goal'.
        // This gives the number of subarrays with an exact sum equal to 'goal'.
        return func(nums, goal) - func(nums, goal - 1);
    }
};

