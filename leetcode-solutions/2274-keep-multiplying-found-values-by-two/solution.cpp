class Solution {
public:
    int findFinalValue(vector<int>& nums, int org) {
        multiset<int>st(nums.begin(), nums.end());
        while(true){
            if(st.find(org) != st.end()){
                org *= 2;
            }
            else break;
        }
        return org;
    }
};
