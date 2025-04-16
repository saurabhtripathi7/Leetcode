class Solution {
public:
    // subarray, k - count ==>> sliding window
    //keep a map and an iterator j, store freq of each num
    //before j, how many nums[j] have we seen? == no. of pair possible using nums[j] 
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long pairs = 0, res = 0;
        unordered_map<int, int>freq; // number->freq

        while(j < n){
            pairs += freq[nums[j]]; // increase cnt of pairs by no of times we have seen nums[j] before
            freq[nums[j]]++;

            while(pairs >= k){
                res += (n - j); //all nums after it will also result in a good subarray
                //shrink from left, to check for more subarrays
                freq[nums[i]]--;
                pairs -= freq[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};
