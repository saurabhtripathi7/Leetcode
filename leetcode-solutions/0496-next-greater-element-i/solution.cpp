class Solution {
public:

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Stack to store elements from nums2 to find the next greater element
        stack<int> st;
        
        // Hash map (unordered_map) to store the next greater element for each number in nums2
        unordered_map<int, int> mpp;

        // Traverse nums2 from right to left
        // This helps maintain a monotonic stack to track the next greater element
        for(int i = nums2.size() - 1; i >= 0; --i) {
            int curr = nums2[i];  // Current element in nums2

            // Pop elements from the stack until the top of the stack is greater than the current element
            // This maintains the decreasing order in the stack
            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // If the stack is empty, no greater element exists to the right, so set -1
            if(st.empty()) {
                mpp[curr] = -1;
            } 
            // Otherwise, the top element is the next greater element
            else {
                mpp[curr] = st.top();
            }

            // Push the current element onto the stack for further comparisons
            st.push(curr);
        }

        // Result vector to store the next greater element for each element in nums1
        vector<int> res;
        
        // For each element in nums1, use the hash map to find its next greater element from nums2
        for(int i = 0; i < nums1.size(); ++i) {
            res.push_back(mpp[nums1[i]]);
        }

        // Return the result vector
        return res;
    }
};

