class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;
        string ans = "";
        ans.push_back(s[0]);
        for(int i = 1; i < s.length()-1; ++i){
            if(s[i-1] == s[i] && s[i] == s[i+1]){
                continue;
            }else{
                ans.push_back(s[i]);
            }
        }
        ans.push_back(s[s.length()-1]);
        return ans;
    }
};
