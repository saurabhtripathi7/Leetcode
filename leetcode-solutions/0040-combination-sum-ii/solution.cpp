class Solution {
public:
    // Recursive function to find all combinations that sum to the target
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: if the target is reduced to zero, we found a valid combination
        if (target == 0) {
            // Add the current combination (ds) to the result
            ans.push_back(ds);
            return;
        }

        // Check if the current index exceeds the array bounds or if the target becomes negative
        if (ind >= arr.size() || target < 0) {
            return; // Exit if out of bounds or target is negative
        }

        // Option 1: Include the current element and recurse to the next index
        ds.push_back(arr[ind]);
        findCombination(ind + 1, target - arr[ind], arr, ans, ds); // Move to the next index

        ds.pop_back(); // Backtrack after including the element

        // Option 2: Skip the current element to avoid duplicates
        while (ind + 1 < arr.size() && arr[ind] == arr[ind + 1]) {
            ind++; // Skip duplicates
        }
        findCombination(ind + 1, target, arr, ans, ds); // Recur with the next index
    }

    // Main function to initiate the combination finding process
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store all the valid combinations found
        vector<int> ds; // To store a single combination being constructed
        sort(candidates.begin(), candidates.end()); // Sort to help with skipping duplicates
        findCombination(0, target, candidates, ans, ds); // Start the recursive process
        return ans; // Return the list of all combinations found
    }
};

