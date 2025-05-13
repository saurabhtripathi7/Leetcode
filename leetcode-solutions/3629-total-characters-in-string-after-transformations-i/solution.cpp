class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int step = 0; step < t; ++step) {
            vector<int> newFreq(26, 0);
            for (int i = 0; i < 26; ++i) {
                int count = freq[i];
                if (i == 25) { // 'z'
                    newFreq[0] = (newFreq[0] + count) % MOD; // 'a'
                    newFreq[1] = (newFreq[1] + count) % MOD; // 'b'
                } else {
                    newFreq[i + 1] = (newFreq[i + 1] + count) % MOD;
                }
            }
            freq = move(newFreq);
        }

        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            res = (res + freq[i]) % MOD;
        }

        return (int)res;
    }
};

