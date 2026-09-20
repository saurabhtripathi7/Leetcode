class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int prev = 0; // size of previous group
        int curr = 1; // size of current group

        for (int i = 1; i < s.size(); i++) {

            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                // Current group ended.
                ans += min(prev, curr);

                prev = curr;
                curr = 1;
            }
        }
        // Process the final pair of groups
        ans += min(prev, curr);

        return ans;
    }
};