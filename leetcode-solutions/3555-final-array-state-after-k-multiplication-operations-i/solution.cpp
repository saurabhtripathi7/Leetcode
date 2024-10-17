class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < nums.size(); ++i){
            minHeap.push({nums[i], i});
        }

        while(k--){
            auto topPair = minHeap.top();
            minHeap.pop();
            topPair.first *= m;
            minHeap.push(topPair);            
        }
        
        vector<int> res(nums.size());
        while(!minHeap.empty()){
            auto topPair = minHeap.top();
            minHeap.pop();
            res[topPair.second] = topPair.first;
        }
        return res;
    }
};
