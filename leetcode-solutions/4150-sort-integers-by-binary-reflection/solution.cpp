class Solution {
public:
    long long reflect(long long x) {
        long long rev = 0;
        while (x) {
            rev = (rev << 1) | (x & 1);
            x >>= 1;
        }
        return rev;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            long long A = reflect(a);
            long long B = reflect(b);
            if (A != B)
                return A < B;
            return a < b;
        });
        return nums;
    }
};
