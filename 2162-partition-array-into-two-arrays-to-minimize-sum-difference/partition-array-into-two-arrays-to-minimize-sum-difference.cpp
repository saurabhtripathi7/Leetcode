class Solution {
public:
    void generateSubsetSums(int idx, int count, int sum, vector<int>& nums, vector<vector<int>>& subsetSums) 
    {
        if (idx == nums.size()) {
            subsetSums[count].push_back(sum);
            return;
        }
        // Skip curr elem
        generateSubsetSums(idx + 1, count, sum, nums, subsetSums);
        // Pick curr elem
        generateSubsetSums(idx + 1, count + 1, sum + nums[idx], nums, subsetSums);
    }

    int findMinimumDifference(vector<int>& leftSums, vector<int>& rightSums, int totalSum) 
    {
        int minDiff = INT_MAX;

        for (int leftSum : leftSums) 
        {
            int target = totalSum / 2 - leftSum;
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target); // ptr to just greater or equal to target

            // Candidate 1: first element >= target
            if (it != rightSums.end()) 
            {
                int firstPartition = leftSum + *it;
                int secondPartition = totalSum - firstPartition;
                minDiff = min(minDiff, abs(firstPartition - secondPartition));
            }

            // Candidate 2: just previous element
            if (it != rightSums.begin()) 
            {
                --it;
                int firstPartition = leftSum + *it;
                int secondPartition = totalSum - firstPartition;
                minDiff = min(minDiff, abs(firstPartition - secondPartition));
            }
        }

        return minDiff;
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSubsetSums(n + 1);
        vector<vector<int>> rightSubsetSums(n + 1);

        generateSubsetSums(0, 0, 0, left, leftSubsetSums);
        generateSubsetSums(0, 0, 0, right, rightSubsetSums);

        for (int i = 0; i <= n; i++) {
            sort(rightSubsetSums[i].begin(), rightSubsetSums[i].end());
        }

        int answer = INT_MAX;

        for (int leftCount = 0; leftCount <= n; leftCount++) { // leftCount = k
            // send left and right arrays of k and n-k sizes from 2D vec for calc min diff 
            answer = min(answer,
                         findMinimumDifference(leftSubsetSums[leftCount], rightSubsetSums[n - leftCount], totalSum));
        }

        return answer;
    }
};