class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int index = -1;

            for (int i = 1; i < nums.size(); ++i) {
                int sum = nums[i] + nums[i - 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i - 1;
                }
            }

            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);  
            ++ops;
        }

        return ops;
    }

private:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};

