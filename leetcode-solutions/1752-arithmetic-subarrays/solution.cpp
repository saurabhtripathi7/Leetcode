class Solution {
public:
    // Function to check if a sorted subarray is arithmetic
    bool isArithmetic(vector<int>& subarray) {
        int n = subarray.size();
        if (n < 2) return true; // If the subarray has fewer than 2 elements, it's trivially arithmetic

        int diff = subarray[1] - subarray[0]; // Common difference
        for (int i = 2; i < n; i++) {
            if (subarray[i] - subarray[i - 1] != diff) {
                return false; // If any consecutive difference isn't equal, it's not arithmetic
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size(); // Number of queries
        vector<bool> result(m); // Store the result for each query

        for (int i = 0; i < m; i++) {
            // Extract the subarray from nums[l[i]] to nums[r[i]]
            vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);

            // Sort the subarray to check if it can be rearranged to form an arithmetic sequence
            sort(subarray.begin(), subarray.end());

            // Check if the sorted subarray forms an arithmetic sequence
            result[i] = isArithmetic(subarray);
        }

        return result;
    }
};
