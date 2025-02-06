class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int>products;
        for(int i = 0;i<size;i++)
        {
            for(int j = i+1;j<size;j++)
            {
                int pr = nums[i]*nums[j];
                products[pr]++;
            }
        }
        int totaltuple = 0;
        for(auto prod:products)
        {
            int k = prod.second;
            totaltuple+=8*(k*(k-1))/2;
        }
        return totaltuple;
    }
};
