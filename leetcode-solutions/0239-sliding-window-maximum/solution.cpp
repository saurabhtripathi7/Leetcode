#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")

bool init() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    return true;
}

bool _ = init();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>dq;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            // remove indices of prev window which are out of current window
            if(!dq.empty() && dq.front() < i-k+1) dq.pop_front();

            // remove the elements from back/top which are smaller than curr element of nums
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            // add curr index to dq
            dq.push_back(i);

            // add max of curr window (dq.front->element) to res after processing the first 'k' elements
            if(i >= k-1)  res.push_back(nums[dq.front()]); 
        }
        return res;
    }
};
