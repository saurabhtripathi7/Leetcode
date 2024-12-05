auto fastIO = []() {
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    cin.tie(nullptr);           // Untie cin from cout for faster input
    cout.tie(nullptr);          // Untie cout for faster output
    return 0;                   // Return 0 to allow direct invocation
}();
class Solution {
public:
    bool canChange(string start, string target) {
        

        // Step 1: Remove all '_' and check if the order of 'L' and 'R' matches
        string s1 = "", s2 = "";
        for (auto i : start) {
            if (i != '_') s1.push_back(i);
        }
        for (auto i : target) {
            if (i != '_') s2.push_back(i);
        }
        if (s1 != s2) return false;

        // Step 2: Use two pointers to check positions
        int i = 0, j = 0;
        while (i < start.length() && j < target.length()) {
            // Skip '_' in start
            while (i < start.length() && start[i] == '_') i++;
            // Skip '_' in target
            while (j < target.length() && target[j] == '_') j++;

            // If both pointers are within bounds, check movement constraints
            if (i < start.length() && j < target.length()) {
                if (start[i] != target[j]) return false; // Mismatch
                if (start[i] == 'L' && i < j) return false; // 'L' moved right
                if (start[i] == 'R' && i > j) return false; // 'R' moved left
                i++;
                j++;
            }
        }

        return true;
    }
};

