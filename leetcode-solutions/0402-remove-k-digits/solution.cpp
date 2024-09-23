class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;         // Stack to store digits while building the result
        int n = num.length();   // Get the length of the number string
        
        // Iterate through each digit in the number string
        for (int i = 0; i < n; i++) {
            // While the stack is not empty, k > 0, and the top of the stack is greater than the current digit
            // Pop the top of the stack to remove a larger digit (this makes the number smaller)
            while (!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
                st.pop();        // Remove the larger digit
                k--;             // Decrease k as one digit has been removed
            }
            st.push(num[i]);     // Push the current digit onto the stack
        }
        
        // If we still have digits left to remove (k > 0), pop from the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans = "";  // String to hold the result

        // Build the result by popping elements from the stack (in reverse order)
        while (!st.empty()) {
            ans += st.top();  // Append the top element of the stack to the result
            st.pop();         // Pop the element from the stack
        }

        // Remove any leading zeros from the result
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();  // Remove the last character if it is '0'
        }

        // If after removing leading zeros the result is empty, return "0"
        if (ans.empty()) return "0";

        // Reverse the result string to get the correct order (as stack returns reversed order)
        reverse(ans.begin(), ans.end());

        return ans;  // Return the final result
    }
};

