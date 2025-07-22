class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>cumSum(n, 0);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; ++i){
            cumSum[i] = cumSum[i-1] + nums[i]; 
        }
        
        vector<int>mp(10001, -1); //last seen at -1 idx by default
        int i = 0, j = 0;
        int maxSum = 0;
        while(j < n){
            int lastSeenIdx = mp[nums[j]];
            i = max(i, lastSeenIdx +1 ); //jumping i so that subarray from i to j is valid
            int sumTillJ = cumSum[j];  // sum 0 to j
            int sumBeforei = i-1 < 0 ? 0 : cumSum[i-1]; // sum 0 to i-1
            int iTOj = sumTillJ - sumBeforei; //window sum

            maxSum = max(maxSum, iTOj);
            mp[nums[j]] = j;
            j++;
        }
        return maxSum;

    }
};
