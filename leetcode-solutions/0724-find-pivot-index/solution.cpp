class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int index;

        for(index=0; index<n; index++)
        {
            int leftSum=0;
            int rightSum=0;
            for(int left=0; left<index; left++)
            {
                leftSum+=nums[left];
            }
            for(int right=n-1; right>index; right--)
            {
                rightSum+=nums[right];
            }
            if(leftSum==rightSum)
            {
                ans=index;
                break;
            }
            
        }
        return ans;
    }
};
