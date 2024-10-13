class Solution {
public:
    // Rearranges the array to alternate positive and negative numbers
    vector<int> rearrangeArray(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = nums.size();  // Get the size of the input array
        int i, left = 0, right = 1;  // Initialize pointers for positions
        int arr[n];  // Temporary array to store rearranged elements

        // Loop through each element in the input array
        for(i = 0; i < n; i++) {
            if(nums[i] > 0) {
                arr[left] = nums[i];  // Place positive number at 'left' index
                left += 2;             // Move to the next position for positive
            } else {
                arr[right] = nums[i]; // Place negative number at 'right' index
                right += 2;            // Move to the next position for negative
            }
        }

        // Copy the rearranged elements back to the original array
        for(i = 0; i < n; i++) {
            nums[i] = arr[i];  // Update the original array
        }
        
        return nums;  // Return the rearranged array
    }
};

