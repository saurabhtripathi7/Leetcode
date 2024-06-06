class Solution {
public:
    bool rotateString(string s, string goal) {
         // Check if the lengths of s and goal are the same
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Double the string s
        s += s;
        
        // Check if goal is a substring of the doubled string
        return s.find(goal) != string::npos;  // returns npos when substr is not found
    }
};
