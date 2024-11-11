class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) {
            return false;
        }

        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j <= i + k && j < nums.size()) {
                if (nums[i] == nums[j]) {
                    return true;
                }
                j++;
            }
            i++;
        }

        return false;
    }
};
