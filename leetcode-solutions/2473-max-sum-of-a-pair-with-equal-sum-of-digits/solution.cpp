class Solution {
public:
    int digitSum(int num) {
        int dSum = 0;
        while (num > 0) {
            dSum += num % 10;
            num /= 10;
        }
        return dSum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int result = -1;

        for (int i = 0; i < nums.size(); ++i) {
            int sumi = digitSum(nums[i]);
            
            if (mpp.count(sumi)) {
                result = max(result, nums[i] + mpp[sumi]);
            }
            mpp[sumi] = max(mpp[sumi], nums[i]);
        }
        return result;
    }
};

