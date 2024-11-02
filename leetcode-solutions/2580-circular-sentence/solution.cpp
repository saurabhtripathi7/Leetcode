class Solution {
public:
    bool isCircularSentence(string s) {
        if(s[0] != s[s.length()-1]) return false;
        for(int i = 1; i < s.length()-1; ++i){
            if(s[i] == ' '){
                if (s[i-1] != s[i+1]) return false;
            } 
        }
        return true;
    }
};
