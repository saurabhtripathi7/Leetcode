class Solution {
public:
    int binarySearch(vector<int>& arr, int target)
    {
        int s = 0;
        int e = arr.size()-1;
        while (s <= e){
            int mid = s + (e-s)/2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target){
                s = mid+1;
            }
            else {
                e = mid-1;
            }
            
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target);
        

    }
};
