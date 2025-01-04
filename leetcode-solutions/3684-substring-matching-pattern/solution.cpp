class Solution {
public:
    bool hasMatch(string s, string p) {
        int starIndex = -1;
        
        // Find the position of '*' in the pattern
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*') {
                starIndex = i;
                break;
            }
        }
        
        // Split the pattern into two parts: before '' and after ''
        string prefix = p.substr(0, starIndex);
        string suffix = p.substr(starIndex + 1);
        
        // Check if the string s starts with prefix and ends with suffix
        for (int i = 0; i + prefix.size() <= s.size(); i++) {
            // Match prefix
            if (s.substr(i, prefix.size()) == prefix) {
                int suffixStart = i + prefix.size();
                // Check if the remaining part ends with suffix
                if (s.substr(suffixStart).find(suffix) != string::npos) return true;
            }
        }
        return false;
    }
};
