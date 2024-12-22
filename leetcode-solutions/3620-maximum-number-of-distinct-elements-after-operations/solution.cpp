class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> distinctElements;
        int last = INT_MIN;

        for (int num : nums) {
            int start = max(num - k, last + 1);
            for (int newNum = start; newNum <= num + k; ++newNum) {
                if (distinctElements.find(newNum) == distinctElements.end()) {
                    distinctElements.insert(newNum);
                    last = newNum;
                    break;
                }
            }
        }

        return distinctElements.size();
    }
};
