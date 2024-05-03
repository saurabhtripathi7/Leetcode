class Solution {
public:
    int findMin(vector<int>& nums) {
     int n = nums.size();
     int s = 0;
     int e = n-1;
     int ans = INT_MAX;
     while(s<=e){
        int mid = s + (e-s)/2;
        if(nums[s] < nums[e]) // if whole array is sorted, then 1st element is minimum
        {
            return min(ans, nums[s]);
        }
        ans = min(ans, nums[mid]);
        if(nums[s] <= nums[mid]) //we're in the left sorted half, smallest no is in right sorted part
        {
            s = mid+1;
        }
        else{
            e= mid-1;
        }
     }
     return ans;
    }
};
