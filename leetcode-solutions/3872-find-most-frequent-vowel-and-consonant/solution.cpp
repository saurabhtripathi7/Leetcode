class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        string vowels = "aeiou";
        int maxVowelFreq = 0, maxConsonantFreq = 0;

        for (auto &p : freq) {
            char ch = p.first;
            int count = p.second;
            if (vowels.find(ch) != string::npos) {
                maxVowelFreq = max(maxVowelFreq, count);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, count);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};

