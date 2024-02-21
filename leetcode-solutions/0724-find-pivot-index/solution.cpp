class Solution {
public:
    int prefixSumApproach(vector<int>&nums){
        vector<int>lsum(nums.size(), 0);   //creating a vector of size equal to size of nums and all init value as 0
        vector<int>rsum(nums.size(), 0);

        for(int i = 1 ; i < nums.size(); i++){
            lsum[i] = nums[i-1] + lsum[i-1];
        }
        for(int j = nums.size() - 2; j >= 0; j-- ){
            rsum[j] = nums[j+1] + rsum[j+1];
        }
        for(int i = 0; i < nums.size(); i++){
            if (lsum[i] == rsum[i]){
                return i;
            }
        }
        return -1;
    }
    int pivotIndex(vector<int>& nums) {
        return prefixSumApproach(nums);
    }
};
