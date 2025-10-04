class Solution {
public:
    void bs(int s, int e, vector<int>& nums, int target, vector<int>& ans){
        if(s > e){
            return;
        }
        int i = s + (e - s) / 2; // mid
        if(nums[i] == target){
            ans[0] = min(ans[0], i);
            ans[1] = max(ans[1], i);
            // continue search on both sides
            bs(s, i - 1, nums, target, ans);
            bs(i + 1, e, nums, target, ans);
        }
        else if(nums[i] < target){
            bs(i + 1, e, nums, target, ans);
        }
        else{
            bs(s, i - 1, nums, target, ans);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {INT_MAX, INT_MIN}; // {first, last}
        bs(0, nums.size() - 1, nums, target, ans);
        if(ans[0] == INT_MAX) ans[0] = -1;
        if(ans[1] == INT_MIN) ans[1] = -1;
        return ans;
    }
};

