class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum = 0;
        // Calculate the total sum of the array
        for (int k : nums) {
            sum += k;
        }

        multiset<int> st(nums.begin(), nums.end());  // Create a multiset from nums
        int ans = INT_MIN;
    
        // Iterate over each element in nums
        for (int k : nums) {
            // Check if removing 'k' results in an even sum for the remaining elements
            if ((sum - k) % 2 == 0) {
                st.erase(st.find(k));  // Remove one occurrence of 'k' from multiset to avoid self matching
                int p = (sum - k) / 2;  // Compute the value of p
    
                // Check if p exists in the remaining elements of the multiset
                if (st.find(p) != st.end()) {
                    ans = max(ans, k);  // Update the answer with the largest valid 'k'
                }
    
                st.insert(k);  // Reinsert 'k' back into the multiset
            }
        }
    
        return ans;
    }
};
