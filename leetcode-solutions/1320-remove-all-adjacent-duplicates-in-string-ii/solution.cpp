class Solution {
public:
    bool isable(string s){
        for(int i=0;i<s.length();++i){
            if(s[i]!=s[0])return false;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        if(k>s.length()) return s;
        int i= 0;
        int n= s.length();
        while(i<=n-k){
            string temp = s.substr(i,k);
            if(isable(temp)){
                s.erase(i,k);
                i = max(0,i-k);
                n=s.length();
            }
            else i++;
        }
        return s;
    }
};
