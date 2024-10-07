class Solution {
public:
    // Helper function to calculate the number of subarrays with at most 'goal' odd numbers.
    int func(vector<int>& nums, int goal){
        // If the goal is negative, it's not possible to have any subarrays.
        if(goal < 0) return 0;

        // Initialize the sliding window pointers, sum to track the number of odd elements,
        // and cnt to store the number of valid subarrays.
        int l = 0, r = 0, sum = 0, cnt = 0;
        
        // Iterate through the array using the right pointer 'r'.
        while(r < nums.size()){
            // Increment the sum if the current element is odd (nums[r] % 2 == 1).
            sum += nums[r] % 2;
            
            // If the number of odd numbers exceeds the goal, 
            // adjust the left pointer 'l' to reduce the number of odd numbers in the window.
            while(sum > goal){
                sum -= nums[l] % 2;
                l++;
            }
            
            // Add the number of subarrays ending at 'r' and starting from 'l' or before.
            cnt += r - l + 1;
            r++;
        }
        
        // Return the total count of valid subarrays.
        return cnt;
    }

    // Function to calculate the number of subarrays with exactly 'k' odd numbers.
    int numberOfSubarrays(vector<int>& nums, int k) {
        // The result is the difference between the number of subarrays with at most 'k' odd numbers
        // and the number of subarrays with at most 'k-1' odd numbers.
        return func(nums, k) - func(nums, k-1);
    }
};

