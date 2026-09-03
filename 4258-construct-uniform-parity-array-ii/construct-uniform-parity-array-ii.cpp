class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        bool allOdd = true;
        bool allEven = true;

        for(auto &it:nums1){
            if(it%2==0){
                allOdd = false;
                minEven = min(minEven, it);
            }else{
                allEven = false;
                minOdd = min(minOdd, it);
            }
        }
        if(allOdd || allEven){
            return true;
        }
        return minOdd < minEven;
    }
};