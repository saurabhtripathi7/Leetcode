class Solution {
public:
    int xSum(unordered_map<int, int>& freq, int x){
        vector<pair<int,int>>arr;
        for(auto& it:freq){
            int val = it.first;
            int cnt = it.second;
            arr.push_back({cnt,val});
        }
        sort(arr.rbegin(),arr.rend());
        int sum = 0;
        for(int i = 0;i<min((int)arr.size(),x);i++){
            sum+=(arr[i].first)*(arr[i].second);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1);
        for(int i = 0;i<n-k+1;i++){
            unordered_map<int, int> freq;
            for(int j = i;j<i+k;j++){
                freq[nums[j]]++;
            }
            ans[i] = xSum(freq,x);
        }
        return ans;
    }
};
