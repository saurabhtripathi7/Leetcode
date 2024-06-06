class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

    // Start with the first string in the array as the prefix    
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (size_t i = 1; i < strs.size(); ++i) 
        {
            // Compare the prefix with the current string
            while (strs[i].find(prefix) != 0) {
                // Shorten the prefix by one character
                prefix = prefix.substr(0, prefix.length() - 1);

                // If the prefix is empty, return an empty string
                if (prefix.empty()) return "";
            }
        }
    return prefix;
    }
};
