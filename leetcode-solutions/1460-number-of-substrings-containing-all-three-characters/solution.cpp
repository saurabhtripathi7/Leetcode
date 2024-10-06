class Solution {
public:
    int numberOfSubstrings(string s) {
        // Vector to track the last seen indices of characters 'a', 'b', and 'c'
        // lastSeen[0] -> last index of 'a'
        // lastSeen[1] -> last index of 'b'
        // lastSeen[2] -> last index of 'c'
        vector<int> lastSeen(3, -1); // Initialize all to -1 (not seen yet)
        
        int cnt = 0; // To count the number of valid substrings containing 'a', 'b', and 'c'
        
        // Traverse each character in the string
        for (int i = 0; i < s.length(); ++i) {
            // Update the last seen index for the current character ('a', 'b', or 'c')
            lastSeen[s[i] - 'a'] = i;
            
            // Check if all characters ('a', 'b', and 'c') have been seen at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // Calculate the number of valid substrings that end at index i
                // The earliest valid starting point of a substring containing all three characters
                // is the smallest index among lastSeen[0], lastSeen[1], and lastSeen[2].
                // So, the number of valid substrings ending at i is (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]})).
                cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
            }
        }
        
        // Return the total count of valid substrings
        return cnt;
    }
};

