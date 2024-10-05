class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Step 1: Create a vector to store the last index of each character (size 256 for all ASCII characters)
        vector<int> mpp(256, -1); // Initialize all elements with -1, indicating no character has been seen
        
        int l = 0, r = 0; // 'l' is the left pointer, 'r' is the right pointer (sliding window approach)
        int maxLen = 0;   // Variable to store the maximum length of substring without repeating characters
        
        // Step 2: Start sliding the window (right pointer 'r' moves over the string)
        while (r < s.length()) {
            // Check if the current character has already been seen within the current window
            if (mpp[s[l]] != -1) {
                // If the character at index 'r' was seen before and lies within the current window range
                if (mpp[s[r]] >= l) {
                    // Move the left pointer 'l' to the next position after the last occurrence of the character
                    l = mpp[s[r]] + 1;
                }
            }
            
            // Calculate the length of the current window
            int len = r - l + 1;
            // Update maxLen with the maximum length of the non-repeating substring
            maxLen = max(maxLen, len);
            
            // Update the last occurrence of the character at index 'r'
            mpp[s[r]] = r;
            
            // Move the right pointer to the next character
            r++;
        }
        
        // Return the maximum length of the substring without repeating characters
        return maxLen;
    }
};

