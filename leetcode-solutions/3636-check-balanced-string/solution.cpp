class Solution {
public:
    bool isBalanced(string s) {
        int odd = 0, even = 0;
        for(int i = 0; i < s.length(); ++i){
            if(i%2 == 0) {
                even += s[i]-'0';
            }
            else{
                odd += s[i]-'0';
            }
        }
        return even == odd;
    }
};
