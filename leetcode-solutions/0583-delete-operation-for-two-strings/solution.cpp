class Solution {
public:
    int LCS(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]); // for LC Substr -> curr[j] = 0
            }
            prev = curr;
        }

        return prev[m];
    }

    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * LCS(word1, word2);
        //To make strings equal by deletion, keep this LCS and delete everything else.
        //The formula is just counting the characters deleted on both sides.

    }
};
