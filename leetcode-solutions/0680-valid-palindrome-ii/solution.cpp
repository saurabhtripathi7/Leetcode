class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i] != s[j] ) return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;

        while(i<=j){
            if(s[i] == s[j]){
            i++;
            j--;
            }   
            else{
                // 1 char removal is allowed
                // removing 1st chat(i'th char)
                bool ans1 = isPalindrome(s, i+1,j);
                // removing 2nd char(j'th char)
                bool ans2 = isPalindrome(s, i, j-1);
                return ans1 || ans2;
            }
        }
        return true;
    }
};
