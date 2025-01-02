class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Step 1: Determine if each word is valid
        vector<int> valid(words.size(), 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < words.size(); ++i) {
            if (vowels.find(words[i][0]) != vowels.end() &&
                vowels.find(words[i].back()) != vowels.end()) {
                valid[i] = 1;
            }
        }

        // Step 2: Build prefix sum array
        vector<int> prefixSum(valid.size() + 1, 0);
        for (int i = 0; i < valid.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + valid[i];
        }

        // Step 3: Answer each query using prefix sum
        vector<int> ans;
        for (const auto& query : queries) {
            int first = query[0];
            int second = query[1];
            // Get the count in range [first, second]
            ans.push_back(prefixSum[second + 1] - prefixSum[first]);
        }

        return ans;
    }
};

