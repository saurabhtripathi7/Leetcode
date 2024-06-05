class Solution {
public:
void reverseWord(string &word) {
    reverse(word.begin(), word.end());
}

string reverseWords(string s) {
    string ans = "";
    string temp = "";
    
        // Two pointers to manage the extraction of words
        int i = 0;
        int n = s.size();
        // reversing the org string 
        reverse(s.begin(), s.end());
    
        while (i < n) {
        // Skip any leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Collect the word
        while (i < n && s[i] != ' ') {
            temp.push_back(s[i]);
            i++;
        }
        
        // Reverse the collected word
        reverseWord(temp);
        
        // Add the reversed word to the result
        if (!temp.empty()) {
            if (!ans.empty()) {
                ans += " ";
            }
            ans += temp;
            temp.clear();
        }
    }
return ans;
}
};
