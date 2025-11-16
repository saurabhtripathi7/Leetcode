class Solution {
public:
    const int mod = 1e9 + 7;

    int numSub(string s) {
        long long ans = 0;
        long long len = 0;

        for (char ch : s) {
            if (ch == '1') {
                len++;
            } else {
                ans = (ans + (long long)len * (len + 1) / 2) % mod;
                len = 0;
            }
        }

        if (len > 0) {
            ans = (ans + (long long)len * (len + 1) / 2) % mod;
        }

        return (int)ans;
    }
};

