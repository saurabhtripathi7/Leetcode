class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int tSum = 0;
        for(auto n : nums){
            tSum += n;
        }
        int lSum =0, cnt = 0;

        for(int i = 0; i < nums.size()-1; ++i){
            lSum += nums[i];
            int rSum = tSum - lSum;
            if((lSum %2 ) == (rSum%2)){
                cnt++;
            }
        }
        return cnt;
    }
};
