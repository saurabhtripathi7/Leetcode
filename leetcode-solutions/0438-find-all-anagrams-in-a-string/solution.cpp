class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if(n < m) return {};
        vector<int> pMap(26, 0), sMap(26, 0);
        vector<int>res;
        for (int i = 0; i < m; ++i) {
            pMap[p[i] - 'a']++;
            sMap[s[i] - 'a']++;
        }
        if (sMap == pMap)
            res.push_back(0); // for 1st window's ans

        for(int i = m; i < n; i++) {
            sMap[s[i] - 'a']++;    
            sMap[s[i - m] - 'a']--;  // remove old char

            if(sMap == pMap) res.push_back(i - m + 1);
        }
        return res;
    }
};
