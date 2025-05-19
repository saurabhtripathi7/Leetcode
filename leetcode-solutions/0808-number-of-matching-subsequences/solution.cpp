class Solution {
public:
    bool isSubsequence(const string& word, const string& s) {
        int i = 0, j = 0;
        // i: curr char in word string
        // j: curr char in s string
        while (i < word.size() && j < s.size()) {
            if (word[i] == s[j]) i++; //
            j++; // always moves
        }
        return i == word.size();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, bool>memo; 
        //Memoization map to store whether a word is a subsequence of 's' or not

        int ans = 0;
        for (const string& word : words) {
            if (memo.count(word)) { // If we have already checked this word before
                ans += memo[word];  // Use cached result (true/false → 1/0) and add to answer
            } else {
                bool match = isSubsequence(word, s); // Check if word is a subsequence of 's'
                memo[word] = match; // Store the result in memo map for future use
                ans += match; // Add 1 if it's a matching subsequence, else add 0
            }
        }
        return ans;
    }
};
