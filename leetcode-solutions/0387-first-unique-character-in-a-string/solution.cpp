class Solution {
public:
    int firstUniqChar(string s) {
        int count[26]={0};  // init count of each char is 0
        // counting the freq of each char in s
        for(auto ch: s){
            count[ch-'a'] = count[ch-'a']+1; //increment the count of each index by 1
        }
        for(int i=0; i<s.length(); i++){
            if(count[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};
