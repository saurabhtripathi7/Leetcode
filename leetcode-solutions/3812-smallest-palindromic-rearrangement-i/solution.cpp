class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string l;
        for (int i = 0; i < 26; i++) {
            l.append(freq[i] / 2, 'a' + i);
        }

        string center;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                center = string(1, 'a' + i);
                break;
            }
        }

        string r = l;
        reverse(r.begin(), r.end());

        return l + center + r;
    }
};
