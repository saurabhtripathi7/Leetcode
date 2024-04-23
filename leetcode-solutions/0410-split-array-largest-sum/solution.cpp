class Solution {
public:
    bool isPossibleSolution(vector<int>& arr, int n, int m, int sol){
        int countStudent = 1;
        int pageSum = 0;
        for(int i=0; i<n; i++){
            if(arr[i]>sol) return false;
            if(pageSum + arr[i] <= sol){
                pageSum+=arr[i];
            }
            else{
                countStudent++;
                pageSum=arr[i];
                if(countStudent > m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int s =0;
        int e = accumulate(nums.begin(), nums.end(),0);
        int ans = -1;
        if (k > n) return -1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if (isPossibleSolution(nums, n, k, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
