class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it: nums){
            freq[it]++;
        }
        vector<int>res;
        for(auto pair:freq){
            if(pair.second == 2) res.push_back(pair.first);
        }
        return res;
    }
};
