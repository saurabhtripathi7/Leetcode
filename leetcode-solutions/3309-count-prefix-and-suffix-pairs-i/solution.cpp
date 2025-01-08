class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        for(int i = 0; i < words.size(); ++i){
            string word1 = words[i];
            int len = word1.length();
            for(int j = i+1; j < words.size(); ++j){
                string word2 = words[j];
                int len2 = word2.length();
                if(word2.substr(0, len) == word1 && word2.substr(len2 - len, len) == word1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
