class Solution {
public:
    void toLower(string &str){
        for(char &c:str){
            c = tolower(c);
        }
    }
    bool isPalindrome(string s) {
        string str = "";
        for(auto i:s){
            if(isalnum(i))
                str += i;
        }
        toLower(str);

        int i = 0;
        int j = str.length()-1;
        while(i<=j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};
