class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int>ans;

        int left = 0, right = n;

        for(auto ch: s){
            if(ch == 'I'){
                ans.push_back(left++);
            }
            else{
                ans.push_back(right--);
            }
        }
        if(s[n-1] == 'I') ans.push_back(left);
        else{
            ans.push_back(right);
        }
        return ans;

    }
};
