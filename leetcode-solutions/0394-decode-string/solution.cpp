class Solution {
public:
    string helper(string& s, int& index) {
        string result = "";
        int k = 0;

        while (index < s.size()) {
            char c = s[index];

            if (isdigit(c)) {  // If it's a number, calculate the repetition count
                k = k * 10 + (c - '0');
                index++;
            }
            else if (c == '[') {  // If we encounter '[', recursively decode the substring inside
                index++;  // Skip the '['
                string decoded = helper(s, index);  // Decode the string inside brackets
                while (k--) {
                    result.append(decoded);  // Repeat the decoded substring 'k' times
                }
                k = 0;  // Reset the multiplier after using it
            }
            else if (c == ']') {  // If we encounter ']', return the current decoded result
                index++;  // Skip the ']'
                return result;
            }
            else {  // If it's a regular character, append it to the result
                result += c;
                index++;
            }
        }

        return result;
    }

    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
};

