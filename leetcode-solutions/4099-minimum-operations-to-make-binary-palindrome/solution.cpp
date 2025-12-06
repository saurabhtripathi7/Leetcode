class Solution {
public:
    bool isBinPalindrome(int x) {
        vector<int> bits;
        while (x > 0) {
            bits.push_back(x & 1);
            x >>= 1;
        }

        int l = 0, r = (int)bits.size() - 1;
        while (l < r) {
            if (bits[l] != bits[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        const int LIMIT = 20000;

        static vector<int> pals;
        static bool initialized = false;
        if (!initialized) {
            for (int x = 1; x <= LIMIT; ++x) {
                if (isBinPalindrome(x)) {
                    pals.push_back(x);
                }
            }
            initialized = true;
        }

        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int best = INT_MAX;
            for (int p : pals) {
                int diff = abs(p - x);
                if (diff < best)
                    best = diff;
            }
            ans[i] = best;
        }

        return ans;
    }
};
