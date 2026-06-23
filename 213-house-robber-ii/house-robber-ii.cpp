class Solution {
public:
    int houseRobber1(vector<int>& nums) {
        int n = nums.size();

        int last = nums[0], secondLast = 0;
        for(int i = 2; i <= n; ++i){
            int pick = nums[i-1] + secondLast;
            int skip = last;
            secondLast = last;
            last = max(pick, skip);
        }
        return last;
    }

    int rob(vector<int>& nums) {
        vector<int>temp1 = nums, temp2 = nums;
        // first and last house cant be robber together
        temp1.pop_back(); // leave last house
        temp2.erase(temp2.begin()); // leave 1st house

        return max(houseRobber1(temp1), houseRobber1(temp2)); // find max from both cases
    }
};