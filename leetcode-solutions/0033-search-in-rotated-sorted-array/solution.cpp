class Solution {
public:
    int binarySearch(vector<int>& arr, int s, int e, int target){
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] == target) 
                return mid;
            else if (target > arr[mid]) {
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return -1;
    }
    int pivotIndex(vector<int>& arr){
        int s = 0;
        int n = arr.size();
        int e = n-1;
        
        while (s <= e){
            int mid = s + (e-s)/2;
            if (s == e) return 0;            
            else if (mid + 1 < n && arr[mid] > arr[mid + 1])
                return mid;
            else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid]) 
                return mid-1;
            else if ( arr[s] <= arr[mid] ){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    return -1;

    }

    int search(vector<int>& nums, int target) {
        int pivot= pivotIndex(nums);
        int ans = -1;
        if(target >= nums[0] && target <= nums[pivot]){
            ans = binarySearch(nums, 0, pivot, target);
        }
        else{
            ans = binarySearch(nums, pivot+1, nums.size()-1, target);
        }
        return ans;


    }
};
