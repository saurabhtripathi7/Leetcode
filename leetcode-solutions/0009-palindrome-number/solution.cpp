class Solution {
public:
    bool isPalindrome(int x) {
    
    string str = to_string(x);
    string str2=str;
    int len=str.length();
    // reversing
    reverse(str.begin(), str.end());
    if(str==str2)
    return true;
    else 
    return false;
    }
};
