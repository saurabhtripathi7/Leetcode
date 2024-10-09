class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i+1; j < nums.size(); ++j){
                int exp = (nums[i]-1)*(nums[j]-1);
                maxi = max(maxi, exp);
            }
        }
        return maxi;
    }
};
