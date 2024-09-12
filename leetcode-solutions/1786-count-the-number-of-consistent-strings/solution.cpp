class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt= words.size();
        for(int i = 0; i < words.size(); ++i){
            for(int j = 0; j < words[i].length(); ++j){
                if(allowed.find(words[i][j]) == std::string::npos){
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};
