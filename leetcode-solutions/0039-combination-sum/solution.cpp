class Solution {
public:
    // Recursive function to find all combinations that sum to the target
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if we have considered all elements
        if (ind == arr.size()) {
            // If the target is reduced to zero, we found a valid combination
            if (target == 0) {
                ans.push_back(ds); // Add the current combination (ds) to the result
            }
            return; // Exit the function as no more elements are left to consider
        }

        // Option 1: Include the current element if it's less than or equal to the target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]); // Add the current element to the combination
            // Recur with the same index (ind) to allow using the same element again
            findCombination(ind, target - arr[ind], arr, ans, ds);
            ds.pop_back(); // Backtrack: remove the last added element to try the next possibility
        }

        // Option 2: Exclude the current element and move to the next index
        findCombination(ind + 1, target, arr, ans, ds); // Recur with the next index
    }
    
    // Main function to initiate the combination finding process
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store all the valid combinations found
        vector<int> ds; // To store a single combination being constructed
        // Start the recursive search from index 0 and the given target
        findCombination(0, target, candidates, ans, ds);
        return ans; // Return the list of all combinations found
    }
};

