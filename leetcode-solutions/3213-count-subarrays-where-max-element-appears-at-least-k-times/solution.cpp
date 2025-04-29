class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxE = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long ans = 0;
        int maxCnt = 0;
        while(j < n){
            if(nums[j] == maxE){
                maxCnt++;
            }
            while(maxCnt >= k){
                ans += n-j;

                //b4 removing check if ith is maxE, decrement cnt
                if(nums[i] == maxE){
                    maxCnt--;
                }
                i++; //move i fwd
            }
            j++;
        }
        return ans;
    }
};
