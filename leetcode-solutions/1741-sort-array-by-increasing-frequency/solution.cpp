class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        // Step 2: Use a custom comparator to sort by frequency and by value in descending order
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            // If frequencies are the same, sort by value in descending order
            if (a.first == b.first) {
                return a.second < b.second;  // Descending order of values
            }
            // Otherwise, sort by frequency in ascending order
            return a.first > b.first;  
        };

        // Min-heap based on the custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minH(cmp);

        // Step 3: Push elements into the heap
        for (auto& pair : mpp) {
            minH.push({pair.second, pair.first});
        }

        // Step 4: Extract elements from the heap and build the result
        vector<int> res;
        while (!minH.empty()) {
            int freq = minH.top().first;
            int val = minH.top().second;

            // Push the number 'freq' times into the result
            for (int i = 0; i < freq; ++i) {
                res.push_back(val);
            }
            minH.pop();
        }

        return res;
    }
};
