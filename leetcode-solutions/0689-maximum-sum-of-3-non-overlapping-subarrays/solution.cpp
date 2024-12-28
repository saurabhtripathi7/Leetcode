class Solution {
public:

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sums(n - k + 1); // Sums of subarrays of size k
    vector<int> left(n - k + 1); // Best left subarray index up to index i
    vector<int> right(n - k + 1); // Best right subarray index from index i onwards
    
    // Calculate sums of all subarrays of size k
    int currentSum = accumulate(nums.begin(), nums.begin() + k, 0);
    sums[0] = currentSum;
    for (int i = 1; i <= n - k; ++i) {
        currentSum += nums[i + k - 1] - nums[i - 1];
        sums[i] = currentSum;
    }
    
    // Populate the left array
    int bestLeft = 0;
    for (int i = 0; i <= n - k; ++i) {
        if (sums[i] > sums[bestLeft]) {
            bestLeft = i;
        }
        left[i] = bestLeft;
    }
    
    // Populate the right array
    int bestRight = n - k;
    for (int i = n - k; i >= 0; --i) {
        if (sums[i] >= sums[bestRight]) {
            bestRight = i;
        }
        right[i] = bestRight;
    }
    
    // Find the maximum sum using the middle subarray
    vector<int> result(3);
    int maxSum = 0;
    for (int middle = k; middle <= n - 2 * k; ++middle) {
        int leftIndex = left[middle - k];
        int rightIndex = right[middle + k];
        int totalSum = sums[leftIndex] + sums[middle] + sums[rightIndex];
        if (totalSum > maxSum) {
            maxSum = totalSum;
            result = {leftIndex, middle, rightIndex};
        }
    }
    
    return result;
}
};
