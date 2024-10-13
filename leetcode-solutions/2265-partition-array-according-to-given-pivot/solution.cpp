class Solution {
public:
    // Rearranges the array around a pivot
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();  // Size of input array
        vector<int> v;       // Vector to store rearranged elements

        int count = 0;       // Count occurrences of the pivot
        
        // First pass: Add elements less than pivot and count pivots
        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                v.push_back(nums[i]);  // Add numbers < pivot
            }
            else if(nums[i] == pivot) {
                count++;                // Count pivots
            }
        }

        // Add the pivot elements based on their count
        while(count--) {
            v.push_back(pivot);        // Add pivot to result
        }

        // Second pass: Add elements greater than pivot
        for(int i = 0; i < n; i++) {
            if(nums[i] > pivot) {
                v.push_back(nums[i]);   // Add numbers > pivot
            }
        }

        return v;  // Return the rearranged vector
    }
};

