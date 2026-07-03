class Solution {
public:
    void generateSubsetSums(vector<int>& arr, int idx, int sum, vector<int>& subsetSums) {
        if (idx == arr.size()) {
            subsetSums.push_back(sum);
            return;
        }
        // Don't take current element
        generateSubsetSums(arr, idx + 1, sum, subsetSums);
        // Take current element
        generateSubsetSums(arr, idx + 1, sum + arr[idx], subsetSums);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left, right;
        int mid = n / 2;

        for (int i = 0; i < mid; ++i) left.push_back(nums[i]);
        for (int i = mid; i < n; ++i) right.push_back(nums[i]);

        vector<int> leftSubsetSums, rightSubsetSums;

        generateSubsetSums(left, 0, 0, leftSubsetSums);
        generateSubsetSums(right, 0, 0, rightSubsetSums);

        sort(rightSubsetSums.begin(), rightSubsetSums.end()); // for using Binary Search

        int ans = INT_MAX;

        for (int curr : leftSubsetSums) {
            int need = goal - curr;
            auto it = lower_bound(rightSubsetSums.begin(), rightSubsetSums.end(), need);

            if (it != rightSubsetSums.end())
                ans = min(ans, abs(goal - (curr + *it)));

            if (it != rightSubsetSums.begin()) {
                --it;
                ans = min(ans, abs(goal - (curr + *it)));
            }
        }
        return ans;
    }
};