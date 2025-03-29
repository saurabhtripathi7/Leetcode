class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int org1 = 0;
        for (char c : s) {
            if (c == '1') ++org1;
        }
        
        string t = "1" + s + "1";
        int m = t.size();
        
        //Segments: (character, count)
        vector<pair<char,int>> segs;
        char cur = t[0];
        int count = 1;
        for (int i = 1; i < m; i++) {
            if (t[i] == cur) {
                count++;
            } else {
                segs.push_back({cur, count});
                cur = t[i];
                count = 1;
            }
        }
        segs.push_back({cur, count});
        
        int maxGain = 0;
        
        for (int i = 1; i < segs.size() - 1; i++) {
            if (segs[i].first == '1') {
                if (segs[i-1].first == '0' && segs[i+1].first == '0') {
                    int gain = segs[i-1].second + segs[i+1].second;
                    maxGain = max(maxGain, gain);
                }
            }
        }
        
        int ans = org1 + maxGain;
        return ans > n ? n : ans;
    }
};
