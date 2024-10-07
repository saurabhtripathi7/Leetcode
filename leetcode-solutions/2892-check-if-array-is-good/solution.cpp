class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi = INT_MIN;
        for(auto i:nums){
            maxi = max(maxi, i);
        }
        if(nums.size() != maxi+1) return false;
        
        vector<int>freq(maxi+1, 0);
        for (int i : nums) {
            if (i > maxi) return false; 
            freq[i]++;
        }

        for (int i = 1; i < maxi; ++i) {
            if (freq[i] != 1) return false;
        }

        if (freq[maxi] != 2) return false; 

        return true;

    }
};
