class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.size(), m = t.size();  // Get the lengths of the strings
        if (m - n) return 0;              // If lengths are different, return false
        
        if (s == t) {                     // If strings are of same length
            map<int, int> mp;             // Create a frequency map for characters
            for (auto x : s) mp[x]++;     // Count frequencies of characters in s
            for (auto x : mp)             // Check for any character that appears more than once
                if (x.second > 1) return 1; // If found, return true (valid buddy string)
            return 0;                     // Otherwise, return false
        }
        
        int dif = 0;                      // Initialize the difference counter
        string s1, t1;                   // Initialize strings to hold differing characters
        for (auto i = 0; i < n; i++) {   // Loop through both strings
            if (s[i] - t[i]) {            // If characters at the same position are different
                dif++;                    // Increment the difference counter
                s1 += s[i];               // Add differing character from s to s1
                t1 += t[i];               // Add differing character from t to t1
            }
        }

        if (dif != 2) return 0;          // If not exactly two differences, return false

        sort(s1.begin(), s1.end());      // Sort differing characters from s
        sort(t1.begin(), t1.end());      // Sort differing characters from t

        if (s1 == t1) return 1;          // If sorted differing characters are equal, return true
        return 0;                        // Otherwise, return false
    }
};

