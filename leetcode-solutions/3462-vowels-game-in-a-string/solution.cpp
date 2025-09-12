class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch== 'e' || ch== 'i' || ch== 'o'||ch=='u';
    }
    bool doesAliceWin(string s) {
        for(char ch:s){
            if(isVowel(ch))
            return true;
        }
        return false;
    }
};
