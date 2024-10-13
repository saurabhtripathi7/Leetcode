class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word ="";
        for(int i=0; i < word1.length() || i < word2.length(); i++ ){
            if( i < word1.length()){
            word.push_back(word1[i]);
            }
            if( i < word2.length()) { 
                word.push_back(word2[i]);
            }
        }
        return word;
    }
};
