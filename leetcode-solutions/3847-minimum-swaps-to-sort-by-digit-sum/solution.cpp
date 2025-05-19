class Solution {
public:
        int digitSum(int num) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build the target sorted array
        vector<pair<int, int>> sorted; // (digitSum, num)
        for (int num : nums)
            sorted.push_back({digitSum(num), num});

        sort(sorted.begin(), sorted.end()); // sorts by digitSum then num

        // Step 2: Map sorted order to original index
        unordered_map<int, int> valToIndex;
        for (int i = 0; i < n; ++i)
            valToIndex[nums[i]] = i;

        // Step 3: Simulate swaps using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            int targetNum = sorted[i].second;
            int currIndex = valToIndex[targetNum];

            if (visited[i] || currIndex == i)
                continue;

            // Start a cycle
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                int nextNum = sorted[j].second;
                j = valToIndex[nextNum];
                ++cycle_size;
            }
            if (cycle_size > 1)
                swaps += cycle_size - 1;
        }

        return swaps;
    }
};
