class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx = 0, maxLen = 1;

        auto expand = [&](int l, int r){
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r-l+1 > maxLen){
                    startIdx = l;
                    maxLen = r-l+1;
                }
                l--;
                r++;
            }
        };

        for(int i = 0; i < s.size(); ++i){
            expand(i, i); // one center of palindrome
            expand(i, i+1); // two center of palindrome
        }

        return s.substr(startIdx, maxLen);
    }
};