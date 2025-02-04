class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(); 
        int ans = 0;
        int temp = nums[0];
        for(int i = 1;i<n;i++)
        {   
            if(nums[i]>nums[i-1])
            temp+=nums[i];
            else
            {
                ans = max(temp,ans);
                temp= nums[i];
            }
        }
return max(ans,temp);
    }
};
