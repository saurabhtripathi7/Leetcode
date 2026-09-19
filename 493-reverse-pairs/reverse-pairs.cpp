class Solution {
public:
    void merge(vector<int>&nums, int l, int mid, int r){
        vector<int>temp;
        int i = l;
        int j = mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }


        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }
        // copy temp into nums;
        int idx = 0;
        for(int i = l;i<=r;i++){
            nums[i] = temp[idx];
            idx++;
        }

    }
    int count(vector<int>&nums, int l, int mid, int r){
        int ans = 0;
        int i = l;
        int j = mid+1;
        while(i<=mid && j<=r){
            if(nums[i] > 2*1LL*nums[j]){
                ans += (mid-i+1);
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
    int mergeSort(vector<int>&nums, int l, int r){
        int mid = l+(r-l)/2;
        if(l==r){
            return 0;
        }
        int ans = 0;
        ans += mergeSort(nums, l, mid);
        ans += mergeSort(nums, mid+1, r);
        ans += count(nums, l, mid, r);
        merge(nums, l, mid, r);
        
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};