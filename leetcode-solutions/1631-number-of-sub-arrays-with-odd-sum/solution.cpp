class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7; // To prevent integer overflow, we will take the modulo of the result
        int ans = 0;        // This variable stores the total number of subarrays with an odd sum
        int n = arr.size(); // Get the size of the input array

        int cumSum = 0;     // This variable keeps track of the cumulative sum as we iterate

        // Variables to track the count of even and odd prefix sums
        int evensumCnt = 1; // Initialize to 1 to account for the empty prefix (sum = 0)
        int oddsumCnt = 0;  // No odd prefix sum initially

        // Iterate through each element of the array
        for(int i = 0; i < n; ++i){
            cumSum += arr[i]; // Update the cumulative sum

            // Check if the cumulative sum is even or odd
            if(cumSum % 2 == 0){
                // If the cumulative sum is even:
                // Any previous odd prefix sum will form an odd subarray when combined with the current sum
                ans = (ans + oddsumCnt) % MOD; // Add the count of odd prefix sums to the answer
                evensumCnt++; // Increment the count of even prefix sums
            }
            else{
                // If the cumulative sum is odd:
                // Any previous even prefix sum will form an odd subarray when combined with the current sum
                ans = (ans + evensumCnt) % MOD; // Add the count of even prefix sums to the answer
                oddsumCnt++; // Increment the count of odd prefix sums
            } 
        }
        return ans; // Return the total number of odd subarrays
    }
};

/*
Explanation of the logic:

1. **Why do we track even and odd prefix sums?**
   - An odd subarray sum is formed when:
     - Odd cumulative sum - Even cumulative sum = Odd subarray
     - Even cumulative sum - Odd cumulative sum = Odd subarray

2. **Initial Conditions:**
   - `evensumCnt = 1` because the prefix sum before the first element is considered 0 (which is even).
   - `oddsumCnt = 0` as no odd prefix sum exists initially.

3. **Iterating through the array:**
   - If the cumulative sum is even:
     - Add the count of previous **odd** prefix sums to the answer.
     - Increment the `evensumCnt`.
   - If the cumulative sum is odd:
     - Add the count of previous **even** prefix sums to the answer.
     - Increment the `oddsumCnt`.

4. **Why does this work?**
   - We are effectively counting how many odd subarrays end at each index by leveraging the relationship between odd and even prefix sums.

5. **Complexity Analysis:**
   - Time Complexity: `O(n)` because we traverse the array once.
   - Space Complexity: `O(1)` as we only use a few variables (no extra arrays).
*/

