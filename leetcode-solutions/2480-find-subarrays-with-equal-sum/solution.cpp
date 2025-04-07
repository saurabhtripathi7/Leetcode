class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int l = 0;
        int r;
        while(l < n-1){
            r = l + 1;
            int sum = nums[l] + nums[r];
            if(st.count(sum)) return true;
            st.insert(sum);
            l++;
        }
        return false;
    }
};
