class Solution {
public:
    string decodeMessage(string key, string message) {
        // creating  a mapping for each ch in key (mapping each character of key by alphabets)
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: key){
            if(ch != ' ' && mapping[ch] == 0){
                mapping[ch] = start;
                start++; //moving start to next alphabet
            }
        } 
        string ans;
        // using the mapping to decode the message 
        for(auto ch: message){
            if(ch == ' '){
                ans.push_back(' ');
            }
            else{
                char newch = mapping[ch];
                ans.push_back(newch); 
            }
        }
        return ans;
    }
};
