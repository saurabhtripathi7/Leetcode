class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //if(nums.size() == 0) return;

        int index = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                swap(nums[i], nums[index]);
                index++;
            }
        }
        
    }
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int op = n -1;
        for(int i = 0; i < op; ++i ){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        moveZeroes(nums);
        return nums;
    }
};
