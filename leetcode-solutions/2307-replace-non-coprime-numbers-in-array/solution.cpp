class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(int i = 0;i<nums.size();i++)
        {
            while(!result.empty())
            {
                int x = result.back();
                int curr = nums[i];
                if(gcd(x,curr)>1){
                    result.pop_back();
                    nums[i] = lcm(x,curr);
                }
                else
                break;
            }
            result.push_back(nums[i]);
        }
        return result;
    }
};
