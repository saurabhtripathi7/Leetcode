class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        if (nums.empty()) return result; // If the array is empty, return an empty result

        int start = nums[0]; // Start of the current range

        for (int i = 1; i <= nums.size(); ++i) {
            // If the current number does not continue the sequence or it's the end of the array
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    // Single element range
                    result.push_back(to_string(start));
                } else {
                    // Multi-element range
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }
                // Start a new range if applicable
                if (i < nums.size()) start = nums[i];
            }
        }

        return result;
    }
};

