class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        string vowel = "AEIOUaeiou";
        unordered_map<char,int>mpp;
        for(auto ch : s){
            if(isVowel(ch))
            mpp[ch]++;
        }
        int j = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(isVowel(s[i]))
            {
                while(mpp[vowel[j]]==0){
                    j++;
                }

                s[i] = vowel[j];
                mpp[vowel[j]]--;
            }
        }
        return s;
    }
};
