class Solution {
public:
    int minAddToMakeValid(string s) {
        // Initialize a stack to store unmatched opening parentheses
        stack<char> st;

        // Initialize a counter to keep track of unmatched closing parentheses
        int count = 0;

        // Loop through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // If the current character is an opening parenthesis '('
            if (s[i] == '(') {
                // Push it onto the stack, indicating an unmatched opening parenthesis
                st.push(s[i]);
            }
            // If the current character is a closing parenthesis ')'
            else {
                // Check if there is an unmatched opening parenthesis in the stack
                if (st.empty()) {
                    // If the stack is empty, increment the count because we found an unmatched closing parenthesis
                    count++;
                }
                else {
                    // Otherwise, pop an opening parenthesis from the stack (i.e., we matched it with this closing parenthesis)
                    st.pop();
                }
            }
        }

        // Return the total number of unmatched parentheses:
        // 'count' contains unmatched closing parentheses
        // 'st.size()' gives the number of unmatched opening parentheses left in the stack
        return count + st.size();
    }
};
