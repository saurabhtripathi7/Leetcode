class Solution {
public:
    string largestOddNumber(string num) {
        if(num.length() == 0) return "";
        int  n = num.length();
        
        for(int i = 0; i < n; i++){
            char lastChar = num.back(); // Get the last character of the string
            if((lastChar - '0') % 2 != 0){
                return num;
            }
            else{
                num.pop_back();
            }
        }
        return "";
    }
};
