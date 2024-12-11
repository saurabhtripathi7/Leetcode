class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> cnt;

        // Generate all special substrings with repeated characters
        for (int i = 0; i < s.length(); ++i) {
            string str = "";
            for (int j = i; j < s.length(); ++j) {
                if (str.empty() || str.back() == s[j]) {
                    str += s[j];
                    cnt[str]++; // Increment the frequency of this substring
                } else {
                    break; // Stop if the character sequence breaks
                }
            }
        }

        // Find the maximum length of substrings occurring at least thrice
        int maxLen = -1;
        for (auto& pair : cnt) {
            if (pair.second >= 3) {
                maxLen = max(maxLen, (int)pair.first.length());
            }
        }

        return maxLen;
    }
};

