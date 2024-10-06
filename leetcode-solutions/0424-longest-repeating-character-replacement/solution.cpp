class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0; 
        int left = 0, right = 0; // Left and right boundary of the window
        vector<int> hash(26, 0); // Frequency array for characters
        int maxFreq = 0; // Maximum frequency of a single character in the current window

        while(right < s.length()){
            hash[s[right] - 'A']++; // Increment the frequency of the current character
            maxFreq = max(maxFreq, hash[s[right] - 'A']); // Update max frequency

            // If the current window size minus max frequency is greater than k, shrink the window
            if ((right - left + 1) - maxFreq > k) {
                hash[s[left] - 'A']--; // Decrease the frequency of the left character
                left++; // Move the left boundary to the right
            }

            // Update the maximum length of the valid window
            if((right - left + 1) - maxFreq <= k)
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

