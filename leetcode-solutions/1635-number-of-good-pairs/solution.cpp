class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            int k = j - i;  // frequency of nums[i]
            cnt += (k * (k - 1)) / 2;
            i = j;  //move to nxt no
        }
        return cnt;
    }
};

