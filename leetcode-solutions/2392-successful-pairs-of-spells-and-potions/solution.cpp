class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(),potions.end());
        vector<int>result(n);

        for(int i = 0;i<n;i++){
            long long leastRequired = ceil((double)success/spells[i]);
            auto lb = lower_bound(potions.begin(),potions.end(),leastRequired);
            if(lb==potions.end()){
                result[i] = 0;
            }
            else{
                int count = potions.end() - lb;
                result[i] = count;
            }
            
        }
        return result;
    }
};
