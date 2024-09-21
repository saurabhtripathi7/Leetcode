class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();  // Size of the array
        stack<int> st;        // Stack to store elements to find the next greater element
        vector<int> nge(n, -1);  // Initialize the result array 'nge' with -1 for each element
        
        // Traverse the array twice to simulate a circular array. We go from index 2n-1 to 0.
        // The array is hypothetically doubled by taking i = 2n-1 as the last index
        for (int i = 2 * n - 1; i >= 0; --i) {
            // 'i % n' gives the actual index in the original array, as we are simulating a circular traversal
            
            // Pop elements from the stack while the stack's top is less than or equal to the current element
            // We are maintaining a decreasing stack, so we remove smaller or equal elements
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // When 'i' is within the bounds of the original array (i < n), set the next greater element
            if (i < n) {
                // If the stack is not empty, the top element of the stack is the next greater element
                if (!st.empty()) {
                    nge[i] = st.top();
                }
            }
            
            // Push the current element (nums[i % n]) onto the stack
            st.push(nums[i % n]);             
        }
        
        // Return the result array, which contains the next greater elements for each element in the original array
        return nge;
    }
};

