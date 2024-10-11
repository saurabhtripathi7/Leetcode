class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int maxLen = 0;
        int Fcnt = 0, Tcnt = 0;  // Count of 'F' and 'T'
        int l = 0;  // Left pointer

        for (int r = 0; r < ans.length(); ++r) {
            if (ans[r] == 'T') Tcnt++;
            else if (ans[r] == 'F') Fcnt++;

            int mini = min(Tcnt, Fcnt);  // Minimum of Tcnt and Fcnt in the window

            // If the minimum count exceeds 'k', we need to shrink the window from the left
            while (mini > k) {
                if (ans[l] == 'T') Tcnt--;
                else if (ans[l] == 'F') Fcnt--;
                l++;  // Shrink the window
                mini = min(Tcnt, Fcnt);  // Update mini after shrinking the window
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

static const auto fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
