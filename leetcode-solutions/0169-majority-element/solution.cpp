class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); ++i){
            hash[nums[i]]++;
        }

        int majority = 0;
        for(auto it: hash){
            if(2 * it.second > nums.size()){
                majority = it.first;
            }
        }
        return majority;
    }
};
