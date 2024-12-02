class Solution {
public:
    bool isValid(string s) {
    // Create a stack to store opening brackets
    stack<char> st; 

    // Iterate through each character in the string
    for(auto it: s) {
        // If the character is an opening bracket, push it onto the stack
        if(it == '(' || it == '{' || it == '[') 
            st.push(it); 
        else {
            // If we encounter a closing bracket, check if the stack is empty
            // If the stack is empty, there's no matching opening bracket, so return false
            if(st.size() == 0) 
                return false; 
            // Get the top element of the stack (the most recent opening bracket)
            char ch = st.top(); 
            // Remove the top element from the stack
            st.pop(); 

            // Check if the current closing bracket matches the top opening bracket
            // If it matches, continue to the next character
            if((it == ')' and ch == '(') or  
               (it == ']' and ch == '[') or 
               (it == '}' and ch == '{')) 
                continue;
            else 
                // If it doesn't match, the string is invalid
                return false;
        }
    }    
    // After processing all characters, the stack should be empty if the string is valid
    return st.empty(); 
}

};
