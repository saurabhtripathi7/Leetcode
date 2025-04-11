class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                result.push_back(abs(nums[i])); //store if already inverted
            } else {//invert the num if found first time
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        return result;
    }
};
