class Solution {
public:
    int n;
    vector<vector<int>> dp;
    const int NEG = -1000000000; // -1e9 as "impossible"

    int solve(int i, int rem, vector<int>& nums) {
        // Base case: processed all elements
        if (i == n) {
            // If remainder is 0, valid sum (0 from here)
            return (rem == 0) ? 0 : NEG;
        }

        int &ans = dp[i][rem];
        if (ans != INT_MIN) return ans;  // already computed

        // Option 1: skip nums[i]
        int skip = solve(i + 1, rem, nums);

        // Option 2: take nums[i]
        int newRem = (rem + nums[i]) % 3;
        int take = nums[i] + solve(i + 1, newRem, nums);

        ans = max(skip, take);
        return ans;
    }

    int maxSumDivThree(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, vector<int>(3, INT_MIN));
        int res = solve(0, 0, nums);
        return max(0, res);  // in case all paths are impossible, but here nums are positive so res >= 0
    }
};

