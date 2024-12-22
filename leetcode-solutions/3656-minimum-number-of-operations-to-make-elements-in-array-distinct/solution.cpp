class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
    unordered_set<int> seen;

    // While there are duplicates in the array
    while (true) {
        seen.clear();
        bool hasDuplicates = false;

        // Check for duplicates in the current array
        for (int num : nums) {
            if (seen.count(num)) {
                hasDuplicates = true;
                break;
            }
            seen.insert(num);
        }

        // If no duplicates, we're done
        if (!hasDuplicates) break;

        // Perform an operation: remove up to the first 3 elements
        nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
        operations++;
    }

    return operations;
    }
};
