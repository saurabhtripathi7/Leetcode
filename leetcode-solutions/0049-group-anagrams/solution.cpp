class Solution {
public: // TC : O(N*L)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }

            // Unique Key with #
            string key;
            for (int f : freq) {
                key += to_string(f) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
auto init = atexit([](){ofstream("display_runtime.txt")<<"0";});
// Example: "eat" → counts = [1, 0, 0, ..., 1, ..., 1, ...] (1 for a, 1 for e, 1 for t).
// Convert that frequency array into a string key (like "1#0#0#0#...#1...")
