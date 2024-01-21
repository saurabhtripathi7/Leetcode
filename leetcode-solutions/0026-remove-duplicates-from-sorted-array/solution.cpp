class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    int i=0;
    int k=nums[i]-1;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]>k)
            {
            
        nums[i]=nums[j];
        k=nums[j];
        i++;
            }
        }
        return i;
    }
};
