class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int numSum=0;
        int sumN=0;
        for(int i=0; i<=n; i++)
        {
            sumN+=i;
        }
        for(int i=0; i<n; i++)
        {
            numSum+=nums[i];

        }
        
        return sumN-numSum;
    }
    
};
