class Solution {
public:
int binarySearch(vector<int>& arr, int target)
    {
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        while (s <= e){
            int mid = s + (e-s)/2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target){
                ans = mid +1;
                s = mid+1;
            }
            else if (target < arr[mid]){
                ans =mid;
                e = mid-1;
            }
            
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target);
        
    }
};
