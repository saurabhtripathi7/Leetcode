class Solution {
public:
    bool isPalindrome(string &str){
        string s1 = str;
        reverse(s1.begin(), s1.end());
        return s1 == str;
    }
    void solve(string& s,int i,vector<string>& temp,vector<vector<string>>& res){
        int n = s.length();
        if(i == n){
            res.push_back(temp);
            return;
        }
        string buf = "";
        for(int j = i; j < n; j++){
            buf += s[j];
            if(isPalindrome(buf)){
                temp.push_back(buf);
                solve(s,j+1,temp,res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>>res;
        vector<string>current;
        solve(s, 0, current, res);
        return res;
    }
};

