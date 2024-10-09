class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i = 0; i < nums.size(); ++i){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        for(auto pair : mpp){
            minH.push({pair.second, pair.first});

            if(minH.size() > k){
                minH.pop();
            }
        }

        vector<int>res;
        while(!minH.empty()){
            res.push_back(minH.top().second);
            minH.pop();
        }

        return res;      
        
    }
};
