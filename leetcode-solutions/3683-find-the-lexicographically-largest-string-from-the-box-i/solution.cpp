class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1) return word;
        
        int longestPossible = n - (numFriends - 1); //MIK
        string res;
        for(int i = 0; i < n; ++i){ //O(N)
            int canTakeLength = min(longestPossible, n-i);
            res = max(res, word.substr(i, canTakeLength)); //substr take O(N)
        }
        return res; 
    }
};
