class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
        string newStr = "";
        for (size_t i = 0; i < s.length() - 1; i++) {
            int sum = (s[i] - '0') + (s[i + 1] - '0');
            newStr += (sum % 10) + '0';
        }
        s = newStr;
    }
    return s[0] == s[1];
    }
};
