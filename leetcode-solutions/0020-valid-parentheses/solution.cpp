class Solution {
public:
    bool isValid(string s) {
        // Create a stack to keep track of opening brackets
        stack<char> s1;

        // Iterate over each character in the string
        for(auto ch : s) {
            // If the character is an opening bracket, push it onto the stack
            if(ch == '(' || ch == '{' || ch == '[') {
                s1.push(ch);
            } 
            // If the character is a closing bracket
            else if(ch == ')' || ch == '}' || ch == ']') {
                // If the stack is empty, it means there are more closing brackets than opening brackets
                if(s1.empty()) return false;
                
                // Get the top element of the stack
                char top = s1.top();
                
                // Check if the top element of the stack matches the corresponding opening bracket
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {
                    // If it matches, pop the top element from the stack
                    s1.pop();
                } else {
                    // If it doesn't match, it means the brackets are mismatched
                    return false;
                }
            }
        }
        
        // After processing all characters, if the stack is empty, it means all brackets are matched correctly
        return s1.empty();
    }
};

