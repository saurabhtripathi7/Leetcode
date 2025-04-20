class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        long long prevMax = LLONG_MIN;   
        long long currMax  = LLONG_MIN;   
        int cnt = 0;                   

        for (int num : nums) {
            currMax = max(currMax, (long long)num);
            if (currMax >= prevMax) {
                ++cnt;
                prevMax = currMax;       
                currMax  = LLONG_MIN;    
            }
        }

        return cnt;
    }
};

