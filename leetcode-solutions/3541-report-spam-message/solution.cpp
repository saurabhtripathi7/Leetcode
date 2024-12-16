class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int>mpp;
        for(auto word: bannedWords){
            mpp[word]++;
        }
        int cnt =0;
        for(auto word: message){
            if(mpp[word] > 0) cnt++; 
        }


        return cnt > 1;
    }
};
