class Solution {
public:
    bool check(int i, int currSum, string s, int num){
        if(i == s.length()){
            return currSum == num;
        }
        if(currSum > num) return false;

        bool possible = false;
        for(int j = i; j < s.length(); ++j){
            string sub = s.substr(i, j-i+1);
            int val = stoi(sub);

            possible = possible || check(j+1, currSum+val, s, num);

            if(possible == true) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int num = 1; num <= n; ++num){
            int sq = num*num;

            string s = to_string(sq);
            
            if(check(0, 0, s, num) == true){
                ans += sq;
            }
        }
        return ans;
    }
};
