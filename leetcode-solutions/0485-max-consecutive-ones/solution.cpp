class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0, cnt = 0;
        int r = 0;
        while(r < nums.size()){
            if(nums[r] == 1){
                cnt++;
                maxCnt = max(maxCnt, cnt);            
            }
            else{
                cnt = 0;
            }
            r++;
        }
        return maxCnt;
    }
};
