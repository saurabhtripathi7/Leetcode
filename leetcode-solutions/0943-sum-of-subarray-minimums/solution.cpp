class Solution {
public:
    // Function to find the next smaller element for each element in the array
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();  // Get the size of the input array
        vector<int> nse(n);  // Vector to store indices of next smaller elements
        stack<int> st;       // Stack to maintain indices while traversing the array

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Pop elements from the stack while the top element is greater than or equal to the current element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If the stack is empty, no smaller element exists; otherwise, get the index of the next smaller element
            nse[i] = st.empty() ? n : st.top();  
            st.push(i);  // Push the current index onto the stack
        }
        return nse;  // Return the vector containing next smaller elements
    }

    // Function to find the previous smaller or equal element for each element in the array
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();  // Get the size of the input array
        vector<int> psee(n); // Vector to store indices of previous smaller or equal elements
        stack<int> st;       // Stack to maintain indices while traversing the array

        // Traverse the array from left to right
        for (int i = 0; i < n; ++i) {
            // Pop elements from the stack while the top element is greater than the current element
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If the stack is empty, no smaller or equal element exists; otherwise, get the index of the previous smaller or equal element
            psee[i] = st.empty() ? -1 : st.top();  
            st.push(i);  // Push the current index onto the stack
        }
        return psee;  // Return the vector containing previous smaller or equal elements
    }

    // Main function to calculate the sum of subarray minimums
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();                   // Get the size of the input array
        vector<int> nse = findNSE(arr);       // Find next smaller elements
        vector<int> psee = findPSEE(arr);     // Find previous smaller or equal elements
        long long total = 0;                  // Variable to store the total sum of subarray minimums
        const int mod = (int)1e9 + 7;         // Modulus value to prevent overflow

        // Loop through each element to calculate its contribution to the sum
        for (int i = 0; i < n; ++i) {
            int left = i - psee[i];           // Count of subarrays to the left where arr[i] is the minimum
            int right = nse[i] - i;           // Count of subarrays to the right where arr[i] is the minimum

            // Calculate the contribution of arr[i] using long long to prevent overflow
            long long contribution = (long long)right * left % mod * arr[i] % mod; 
            total = (total + contribution) % mod;  // Update the total sum with the contribution
        }
        return total;  // Return the final sum of subarray minimums
    }
};

