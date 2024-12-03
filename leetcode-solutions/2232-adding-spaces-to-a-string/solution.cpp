class Solution {
public:
    string addSpaces(string s, vector<int>& nums) {
        int j = 0;
        string ans = "";
        for(int i = 0; i < s.length(); ++i){
            if(j < nums.size() && i == nums[j] ){
                ans += ' ';
                i--;
                j++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};
