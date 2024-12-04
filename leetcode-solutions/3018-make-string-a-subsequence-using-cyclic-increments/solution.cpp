class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str1.length() < str2.length()) return false;

        int i = 0, j = 0;

        while (i < str1.length() && j < str2.length()) {
            // Case 1: Characters match directly
            if (str1[i] == str2[j]) {
                i++;
                j++;
            }
            // Case 2: Characters match after a cyclic increment
            else if ((str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                i++;
                j++;
            }
            // Case 3: No match
            else {
                i++;
            }
        }

        // If all characters of str2 are matched, return true
        return j == str2.length();
    }
};

