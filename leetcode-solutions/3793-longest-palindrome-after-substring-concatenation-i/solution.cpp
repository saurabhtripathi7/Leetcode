class Solution {
public:
    bool isPalindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    
    int longestPalindrome(string s, string t) {
        vector<string> subsS;
        subsS.push_back(""); 
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                subsS.push_back(s.substr(i, j - i + 1));
            }
        }
        
        vector<string> subsT;
        subsT.push_back(""); 
        int m = t.size();
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                subsT.push_back(t.substr(i, j - i + 1));
            }
        }
        
        int res = 0;
        for (const string &a : subsS) {
            for (const string &b : subsT) {
                string candidate = a + b;
                if (isPalindrome(candidate)) {
                    res = max(res, (int)candidate.size());
                }
            }
        }
        return res;
    }
};

