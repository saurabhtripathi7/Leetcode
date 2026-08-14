class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int>mpp;
        int ans = 0;
        while(r < n){
            char ch = s[r];
            mpp[ch]++;
            while(mpp[ch] > 2){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};