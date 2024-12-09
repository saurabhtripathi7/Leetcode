class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        //create a cumulative array to store count of violating indices
        vector<int>cumCnt(n, 0);
        // cumCnt[i] = total cnt of violating indices till idx i
        for(int i = 1; i < n; ++i){
            if(nums[i]%2 == nums[i-1]%2){ //same parity. increase count 
                cumCnt[i] = cumCnt[i-1]+1;                
            }
            else{ // no parity
                cumCnt[i] = cumCnt[i-1]; // carry orev cnt val
            }
        }
        vector<bool> res(m, 0);
        int i =0;
        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            if(cumCnt[end] - cumCnt[start] == 0){
                res[i] = true;
            }
            i++;
        }
        return res;
    }
};
