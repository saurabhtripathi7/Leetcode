class Solution {
public:
    double SlidingWindow(vector<int>& nums, int& k){
        int i=0, j=k-1, sum=0;

        for(int a =i; a <= j; ++a){
            sum+=nums[a];
        }
        int maxSum = sum;
        ++j;
        while(j < nums.size()){
            sum -= nums[i++];
            sum += nums[j++];
            maxSum = max(sum , maxSum);
        }
        

        double maxAvg = maxSum / (double)k;
        return maxAvg;
    }
    double findMaxAverage(vector<int>& nums, int k) {
       return SlidingWindow(nums,k);
    }
};
