class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long >mp;
        long long n = nums.size();
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]-i]++;
        }
        long long goodpair = 0;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                goodpair+=((it.second)*(it.second-1))/2;
            }
        }
    
    long long totalpair = (n*(n-1))/2;
    return totalpair-goodpair;
    }
};
