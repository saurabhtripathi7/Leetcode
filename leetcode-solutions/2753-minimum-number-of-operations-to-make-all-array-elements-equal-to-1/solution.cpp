class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countOne = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==1){
                countOne++;
            }
        }
        if(countOne>0){
            return n - countOne;
        }
        int currGcd = 0;
        int minOp = INT_MAX;
        for(int i = 0;i<n;i++){
            currGcd = nums[i];
            for(int j = i+1;j<n;j++){
                currGcd = gcd(currGcd,nums[j]);
                if(currGcd==1){
                    minOp = min(minOp,j-i);
                    break;
                }
            }

        }
        if(minOp==INT_MAX){
            return -1;
        }
        else{
            return minOp + (n-1);
        }
    }
};
