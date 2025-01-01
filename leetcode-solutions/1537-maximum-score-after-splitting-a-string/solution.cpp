class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0; // Total number of ones in the entire string
        int totalZeros = 0; // Current count of zeros in the left substring
        int maxScore = 0; // The maximum score achieved

        // Calculate total ones in the string
        for (char ch : s) {
            if (ch == '1') totalOnes++;
        }

        // Iterate through the string to evaluate all possible splits
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') totalZeros++; // Increment zero count for the left part
            else totalOnes--; // Decrement one count for the right part

            // Calculate the current score: zeros in the left part + ones in the right part
            int currentScore = totalZeros + totalOnes;

            // Update the maximum score
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};

