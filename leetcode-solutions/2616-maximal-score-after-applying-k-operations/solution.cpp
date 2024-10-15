class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(),nums.end());
        while(k--){
            ans += pq.top();
            pq.push(ceil(pq.top() / 3.0));
            pq.pop();
        }
        return ans;
    }
};
