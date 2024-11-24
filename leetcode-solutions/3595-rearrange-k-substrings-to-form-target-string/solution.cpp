class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string, int> mp;
        int len = n / k;
        for (int i = 0; i < n; i += len) mp[s.substr(i, len)]++;
        for (int i = 0; i < n; i += len) mp[t.substr(i, len)]--;
        for (auto &p : mp) if (p.second != 0) return false;
        return true;
    }
};
