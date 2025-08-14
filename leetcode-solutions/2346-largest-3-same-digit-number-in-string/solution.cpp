class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        int maxi = -1;
        for(int i = 0; i < n; ++i){
            if(i+1 < n && i+2 < n && num[i] == num[i+1] && num[i+1] == num[i+2] && int(num[i]) > maxi){
                maxi = int(num[i]);
                ans.clear();
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                ans.push_back(num[i]);
            }
        }
        return ans;
    }
};
