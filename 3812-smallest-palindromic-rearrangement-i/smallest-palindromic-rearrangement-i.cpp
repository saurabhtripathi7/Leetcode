class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>freq;
        for(auto &c: s) freq[c]++;
        string left = "";
        char midOddCh = '\0';
        
        for(auto &[ch, cnt]: freq){
            left += string(cnt/2, ch);

            if(cnt%2 == 1 && midOddCh == '\0') midOddCh = ch;    
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + (midOddCh == '\0' ? "" : string(1, midOddCh)) + right;
    }
};