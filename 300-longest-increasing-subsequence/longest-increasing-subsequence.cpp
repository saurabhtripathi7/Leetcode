class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Patience Sorting
        int n = nums.size();
        vector<int>sorted;

        for(int i = 0; i < n; ++i){
            auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]); // just greater or equal element

            if(it == sorted.end()){ // if not found
                sorted.push_back(nums[i]); // insert curr
            }
            else{ // if found
                *it = nums[i]; // replace it with found
            }
        }
        return sorted.size();
    }
};