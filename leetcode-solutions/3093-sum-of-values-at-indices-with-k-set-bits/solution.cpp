class Solution {
public:
    int countSB(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(countSB(i) == k){
                ans += nums[i];
            }
        }
        return ans;
    }
};
