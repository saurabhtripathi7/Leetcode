class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxImpact = -1;
        int count = 0;
        
        for(int i = 0; i < arr.size(); ++i){
            maxImpact = max(maxImpact, arr[i]);
            if(maxImpact == i) count++;
        }
        return count;
    }
};
