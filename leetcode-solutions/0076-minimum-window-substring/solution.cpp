class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0; // Left and right pointers
        int cnt = 0; // Counter for matched characters
        int sIdx = -1; // Starting index of the minimum window
        int minLen = INT_MAX; // Minimum length of the window
        vector<int> hash(256, 0); // Hash map to count characters in t

        // Count the characters in t
        for(int i = 0; i < t.length(); ++i) 
            hash[t[i]]++;

        // Expand the window with the right pointer
        while(r < s.length()){
            // If character at r is in t, increase the count
            if(hash[s[r]] > 0) 
                cnt++;
            hash[s[r]]--; // Decrement the count for the current character

            // Try to contract the window when all characters are matched
            while(cnt == t.length()){
                // Update minimum window if a smaller one is found
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIdx = l; // Update starting index
                }
                // Move the left pointer to shrink the window
                hash[s[l]]++; // Re-increment the count for the character at l
                // If the character count goes back to positive, decrease cnt
                if(hash[s[l]] > 0) 
                    cnt--; // Decrease cnt since we can no longer match this character
                l++; // Move the left pointer to the right
            }
            r++; // Move the right pointer to the right
        }
        
        // Return the minimum window substring or an empty string if no valid window was found
        return (sIdx == -1) ? "" : s.substr(sIdx, minLen);
    }
};

