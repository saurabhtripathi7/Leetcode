class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); ++i){
            freq[nums[i]]++;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(freq[nums[i]] == 2){
                ans.push_back(nums[i]);
                freq[nums[i]] = 0;
            }
        }
        return ans;
    }
};
