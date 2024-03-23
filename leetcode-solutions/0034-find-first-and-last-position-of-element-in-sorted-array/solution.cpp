class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        
        int end = nums.size()-1;
        
        vector<int> result = {-1, -1};
        // finding starting position

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                result[0] = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
        }
        // reset start and end

        start = 0;
        end = nums.size()-1;

        // finding last position
        while (start <= end){
            int mid = start + (end - start)/2;
            
            if(nums[mid] == target){
                result[1] = mid;
                start = mid + 1;
            }
            else if (nums[mid] > target){
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
        }

        return result;
    }
};
