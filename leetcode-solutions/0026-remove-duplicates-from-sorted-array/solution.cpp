class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>val;
        for(auto i:nums){
            val.insert(i);
        }
        nums.clear();
        for (const auto& elem : val) {
            nums.push_back(elem);
        }

        return val.size();
    }
};
