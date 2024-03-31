class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int s = 0;
      int e = n-1;
      while (s <= e)
      {
        int mid = s + (e-s)/2;
        if (nums[mid] == target){
            return mid;
        }
        // in this approach, we'll not apply BS on whole array, instead we'll trim down the search scope for Bin Search
        // if left part is sorted
        if (nums[s] <= nums[mid]){
            if(nums[s] <= target && target <= nums[mid]){
                // means element exists in left part
                e = mid-1;              // left shifting
            }
            else { //when element is not present in left sorted part
                s = mid+1;      // it might be in the right part,  therefore right shifting 
            }
        }
        else{ //if right part is sorted
            if (nums[mid] <= target && target <= nums[e]){
                // element is in right half
                s = mid+1;
            }
            else { // not in right half
                e = mid-1;
                
            }
        }

      }  
      return -1;
    }
};
