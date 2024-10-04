#pragma GCC optimize("O3")
#pragma GCC target("avx2, bmi, bmi2, lzcnt, popcnt")
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();


class Solution { 
public:
    int maxScore(vector<int>& nums, int k) {
        // Initialize sums for left part, right part, and the maximum sum
        int lSum = 0;  // Sum of the first 'k' elements (left part)
        int rSum = 0;  // Sum of the last 'k' elements (right part, to be calculated later)
        int maxSum = 0;  // To keep track of the maximum score we can get

        // Step 1: Calculate the sum of the first 'k' elements (leftmost part)
        for(int i = 0; i < k; ++i){
            lSum += nums[i];  // Add the first 'k' elements to the left sum
        }
        
        // Initially, the maximum score is just taking the first 'k' elements
        maxSum = lSum;

        // Initialize a pointer for the right side of the array, starting from the last element
        int rInd = nums.size() - 1;

        // Step 2: Gradually slide one element from the left part to the right part
        for(int i = k - 1; i >= 0; --i){
            lSum -= nums[i];  // Remove the element from the left sum
            rSum += nums[rInd];  // Add the element from the right side of the array to the right sum
            rInd--;  // Move the right index towards the left
            
            // Update the maximum sum with the new combination of left and right sums
            maxSum = max(maxSum, lSum + rSum);
        }

        // Return the maximum score that can be obtained by selecting 'k' elements
        return maxSum;
    }
};

